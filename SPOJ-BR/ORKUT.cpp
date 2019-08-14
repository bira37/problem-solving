#include <bits/stdc++.h>

using namespace std;

vector <int> adj[31];
int grau[31];
bool vis[31];
map <string,int> mapa;
map <int,string> auxmapa;
int flag =0;
int dfsFlag =0;

void dfs(int n, int fim){
	vis[n]=true;
	for(int i=0; i<adj[n].size(); i++){
		if(adj[n][i]==fim){
			dfsFlag = 1;
			break;
		}
		if(vis[adj[n][i]]==false) dfs(adj[n][i], fim);
	}
}

void ordena(int n){
	queue <int> q;
	for(int i=1; i<=n; i++){
		if(dfsFlag==1) break;
		for(int j=1; j<=n; j++) vis[j]=false;
		dfs(i,i);
	}
	if(dfsFlag) cout << "impossivel";
	else {
		for(int i=1;i<=n;i++){
			if(grau[i] == 0) q.push(i);
		}
		while(!q.empty()){
			int aux = q.front();
			q.pop();
			if(!flag){
				cout << auxmapa[aux];
				flag = !flag;
			}
			else cout << " " << auxmapa[aux];
			for(int i=0; i<adj[aux].size(); i++){
				grau[adj[aux][i]]--;
				if(grau[adj[aux][i]] == 0) q.push(adj[aux][i]);
			}
		}
	}
	cout << endl;
}
		

int main(){
	int n,teste=1;
	while(cin >> n, n!=0){
		mapa.clear();
		auxmapa.clear();
		flag =0;
		dfsFlag =0;
		for(int i=1; i<=n; i++) grau[i]=0;
		for(int i=1; i<=n; i++) adj[i].clear();
		for(int i=1; i<=n; i++){
			string nome;
			cin >> nome;
			mapa[nome] = i;
			auxmapa[i] = nome;
		}
		for(int i=0; i<n; i++){
			string nome1,nome2;
			int g;
			cin >> nome1 >> g;
			grau[mapa[nome1]]=g;
			for(int j=0; j<g; j++){
				cin >> nome2;
				adj[mapa[nome2]].push_back(mapa[nome1]);
			}
		}
		cout << "Teste " << teste++ << endl;
		ordena(n);
		cout << endl;
	}
}
