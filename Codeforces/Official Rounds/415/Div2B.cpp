#include <bits/stdc++.h>
 
using namespace std;
 
struct item{
	long long k, l, more;
};
 
bool cmp(const item & a, const item & b){
	return a.more > b.more;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	int n,f;
	cin >> n >> f;
	item v[n];
	for(int i=0; i<n; i++){
		cin >> v[i].k >> v[i].l;
		if(v[i].k >= v[i].l) v[i].more = 0;
		else {
			v[i].more = min(v[i].l, v[i].k*2) - v[i].k;
		}
	//	cout << v[i].more << endl;
	}
 
	sort(v,v+n,cmp);
	for(int i=0; i<f; i++){
		v[i].k += v[i].more;
	}
	long long ans = 0;
	for(int i=0; i<n; i++){
	//	cout << v[i].k << " " << v[i].l << endl;
		ans+= min(v[i].k,v[i].l);
	}
	cout << ans << endl;
}
