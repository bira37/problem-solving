#include <bits/stdc++.h>
 
using namespace std;
 
map<int, long long> sum;
map<int, long long> uf; 
 
void init(int n){
	for(int i=1; i<=n; i++){
		uf[i] = i;
	}
}
 
int find(int a){
	if(uf[a] == a) return a;
	else {
		uf[a] = find(uf[a]); //after find the leader l, set uf[i] = l, for all i in the set
		return uf[a];
	}
}
 
void merge(int x, int y){
	int a = find(x);
	int b = find(y);
	uf[b] = a;
	sum[a] += sum[b];
}
 
int main(){
	int n;
	cin >> n;
	
	int v[n];
	for(int i=1; i<=n; i++){
		cin >> v[i];
		sum[i] = v[i];
	}
 
	long long ans = 0;
	vector<long long> res;
	int entrada[n];
	for(int i=0; i<n; i++){
		cin >> entrada[i];
	}
	for(int i=n-1; i>=0; i--){
		int x = entrada[i];
		uf[x] = x;
		if(uf.count(x+1) && uf.count(x-1)){
			merge(x, x+1);
			merge(x, x-1);
			ans = max(ans, sum[find(x)]);
		}
		else if(uf.count(x+1)){
			merge(x, x+1);
			ans = max(ans, sum[find(x)]);
		}
		else if(uf.count(x-1)){
			merge(x,x-1);
			ans = max(ans, sum[find(x)]);
		}
		ans = max(ans, sum[find(x)]);
		//cout << ans << endl;
		res.push_back(ans);
	}
	res.pop_back();
	for(int i= res.size()-1; i>=0; i--) cout << res[i] << endl;
	cout << 0 << endl;
}
