#include <bits/stdc++.h>
 
using namespace std;
 
int teste[101];
int adj[101];
bool vis[101];
 
int mmc(int a, int b){
	return a*(b/__gcd(a,b));
}
 
int main(){
	
	int n;
	cin >> n;
	for(int i=0; i<=n; i++){
		teste[i] = 0;
		adj[i] = 0;
		vis[i] = false;
	}
 
	for(int i=1; i<=n; i++){
		cin >> adj[i];
		teste[adj[i]] = 1;
	}
	
	//if all vertex in-degree is > 1, continue
	for(int i=1; i<=n; i++){
		if(teste[i] == 0){
			cout << -1 << endl;
			return 0;
		}
	}
	
	long long ans = 1;
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		vis[i] = true;
		int size = 1;
		int pos = adj[i];
		if(adj[i] == i) continue;
		while(pos != i){
			pos = adj[pos];
			size++;
		}
		if(size%2 == 0) size = size/2;
		ans = mmc(ans, size);
	}
	
	cout << ans << endl;
}
