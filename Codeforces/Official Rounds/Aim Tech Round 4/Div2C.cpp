#include <bits/stdc++.h>
 
using namespace std;
 
struct number{
	int val, idx, real;
};
 
bool vis[112345];
set<int> s[112345];
int k;
number v[112345];
 
void dfs(int u){
	vis[u] = true;
	s[k].insert(v[u].idx);
	if(vis[v[u].real]) return;
	dfs(v[u].real);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		s[i].clear();
		vis[i] = false;
	}
	int order[n];
	for(int i=0; i<n; i++){
		cin >> v[i].val;
		v[i].idx = i;
		order[i] = v[i].val;
	}
	sort(order, order+n);
	for(int i=0; i<n; i++){
		v[i].real = lower_bound(order, order+n, v[i].val) - order;
	}
	k=-1;
	for(int i=0; i<n; i++){
		if(vis[i]) continue;
		k++;
		dfs(i);
	}
	cout << k+1 << endl;
	for(int i=0; i<=k; i++){
		cout << s[i].size();
		for(int x : s[i]){
			cout << " " << x+1;
		}
		cout << endl;
	}
}
