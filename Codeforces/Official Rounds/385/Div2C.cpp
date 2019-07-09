#include <bits/stdc++.h>
#define N (int)1e5+1
#define ii pair<int,int>
#define ff first
#define ss second
 
using namespace std;
 
bool king[N];
bool ufking[N];
int uf[N];
int sz[N];
vector< ii > edges;
 
void init(int n){
  for(int i=1; i<=n; i++){
		uf[i] = i;
		sz[i] = 1;
		king[i] = false;
		ufking[i] = false;
	}
}
 
int find(int n){
	if(uf[n] == n) return n;
	else {
		uf[n] = find(uf[n]);
		return uf[n];
	}
}
 
void merge(int x, int y){
	int a = find(x);
	int b = find(y);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a,b);
	
	uf[b] = a;
	sz[a]+=sz[b];
}
 
long long calc(int n){
	return (n*(n-1))/2;
}
 
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	init(n);
	
	for(int i=0; i<k; i++){
		int x;
		cin >> x;
		king[x] = true;
	}
 
	for(int i=0; i<m; i++){
		int x,y;
		cin >> x >> y;
		edges.emplace_back(x,y);
		if(find(x) != find(y)) merge(x,y);
	}
 
	for(int i=1; i<=n; i++){
		if(king[i]) ufking[find(i)] = true;
	}
	
	int max_king=0;
	
	for(int i=1; i<=n; i++){
		int u = find(i);
		if(ufking[u]){
			if(max_king == 0) max_king = u;
			else {
				if(sz[max_king] < sz[u]){
					max_king = u;
				}
			}
		}
	}
		
	for(int i=1; i<=n; i++){
		int u = find(i);
		if(!ufking[u]){
			merge(max_king, i);
		}
	}
 
	bool vis[n+1];
	for(int i=1; i<=n; i++) vis[i] = false;
	
	long long ans = 0;	
	for(int i=1; i<=n; i++){
		int u = find(i);
		if(!vis[u]){
			vis[u] = true;
			ans+= calc(sz[u]);
		}
	}
 
	cout << ans - edges.size() << endl;
 
}
