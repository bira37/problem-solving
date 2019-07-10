#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
struct par{
	int num, id, res;
};
 
bool cmp1(const par & a, const par & b){
	return a.num < b.num;
}
 
bool cmp2(const par & a, const par & b){
	return a.id < b.id;
}
 
int solve(int pos, par *v, int l, int r){
	int cu = r;
	if(l > r) return -1;
	int ans = -1;
	while(l <= r){
		int m = (l+r)/2;
		if((long long)v[m].num + (long long)v[pos].num < (long long)(1e9)+7LL){
			ans = m;
			l = m+1;
		}
		else r = m-1;
	}
	if(ans != -1) return v[ans].num;
	else return v[cu].num;
}
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		par v[n];
		for(int i=0; i<n; i++){
			scanf("%d", &v[i].num);
			v[i].id = i;
			v[i].res = 0;
		}
 
		sort(v, v+n, cmp1);
 
		for(int i=0; i<n; i++){
			int x1 = solve(i, v, 0, i-1);
			int x2 = solve(i, v, i+1, n-1);
			//cout << x1 << " " << x2 << endl;
			if(x1 == -1) v[i].res = x2;
			else if(x2 == -1) v[i].res = x1;
			else {
				int k1 = ((long long)x1 + (long long)v[i].num)%((long long)(1e9)+7LL);
				int k2 = ((long long)x2 + (long long)v[i].num)%((long long)(1e9)+7LL);
				if(k1 > k2){
					v[i].res = x1;
				}
				else v[i].res = x2;
			}
		}
 
		sort(v, v+n, cmp2);
 
		for(int i=0; i<n; i++){
			if(i) printf(" ");
			printf("%d", (int)((long long)v[i].res+(long long)v[i].num)%((long long)(1e9)+7LL));
		}
		printf("\n");
	}
}
