#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
 
void fill(long long *v, vector<long long> & a, int idx, int n, long long m, long long acc){
	if(idx == n) return;
	if(lower_bound(a.begin(), a.end(), (acc+v[idx])%m) == a.end() || *lower_bound(a.begin(), a.end(), (acc+v[idx])%m) != (acc+v[idx])%m ){
		a.push_back((acc+v[idx])%m);
	}
	fill(v, a, idx+1, n, m, (acc+v[idx])%m);
	fill(v, a, idx+1, n, m, acc);
}
 
long long solve(long long x, vector<long long> & a, long long m){
	int ans = a.size()-1;
	int l = 0, r = a.size()-1;
	while(l <= r){
		int mid = (l+r)>>1;
		if(x+a[mid] < m){
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	return (x+a[ans])%m;
}
 
int main(){
	int n,m;
	cin >> n >> m;
	long long v[n];
	for(int i=0; i<n; i++) cin >> v[i];
	vector<long long> a,b;
	a.push_back(0);
	b.push_back(0);
	fill(v, a, 0, n/2, m, 0);
	fill(v, b, n/2, n, m, 0);
	for(int x : a) x%=m;
	for(int x : b) x%=m;
	long long ans = 0;
	sort(b.begin(), b.end());
	for(long long x : a){
		ans = max(ans, solve(x, b, m));
	}
	cout << ans << endl;
}
