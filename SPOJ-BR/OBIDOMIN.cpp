#include <bits/stdc++.h>

using namespace std;

bool vis[201];
vector<int> edges;
vector<int> adj[7];
vector<int> eu;

void euler(int v){
	for(int i=0; i< adj[v].size(); i++){
		int id = adj[v][i];
		int u = edges[id];
		if(!vis[id]){
			vis[id] = vis[id^1] = true;
			euler(u);
		}
	}
	eu.push_back(v);
}

int main(){
	int n,teste=1;
	while(cin >> n, n!=0){
		edges.clear();
		eu.clear();
		int impar=0;
		int ini =0;
		for(int i=0; i<=6; i++) adj[i].clear();
		for(int i=0; i<=200; i++) vis[i] = false;
		for(int i=0; i<n; i++){
			int x,y;
			cin >> x >> y;
			ini = x;
			edges.push_back(y);
			edges.push_back(x);
			adj[x].push_back(edges.size()-2);
			adj[y].push_back(edges.size()-1);
		}
		for(int i=0; i<7; i++){
			if(adj[i].size() % 2){
				ini = i;
				impar++;
			}
		}
		cout << "Teste " << teste++ << endl;
		if(impar == 0 || impar == 2){
			euler(ini);
			if(eu.size() == n+1) cout << "sim" << endl;
			else cout << "nao" << endl;
		}
		else cout << "nao" << endl;
		cout << endl;
	}
}

