#include <bits/stdc++.h>

using namespace std;

struct par{
	int v;
	int d;
	char l;
};

struct edge{
	int c;
	char l;
};

bool operator<(par x, par y) {
		if(x.d <= y.d) return false;
		else return true; 
}

vector <int> adj[4002];
bool vis[4002][27];
bool vis2[4002];
vector <edge> adj_cost[4002];
int dist[4002];
map <string, int> mapa;


void calculaMenorDist(int n){
	priority_queue <par> q;
	par vertice;
	vertice.v = n;
	vertice.d=0;
	vertice.l = 96;
	q.push(vertice);
	while(!q.empty()){
		par vertice = q.top();
		q.pop();
		//cout << "Topo:" << endl;
		//cout << "vertice: " << vertice.v << " custo: " << vertice.d << " letra: " << vertice.l << endl;
		if(vis[vertice.v][vertice.l-96] == true) continue;
		if(vis2[vertice.v] == true && dist[vertice.v] > vertice.d || (vis2[vertice.v]==false)) dist[vertice.v] = vertice.d;
		vis[vertice.v][vertice.l-96]=true;
		vis2[vertice.v] = true;
		//cout << "Entra na heap:" << endl;
		for(int i=0; i< adj[vertice.v].size(); i++){
			if(vis[adj[vertice.v][i]][adj_cost[vertice.v][i].l-96] == true) continue;
			if(vertice.d+adj_cost[vertice.v][i].c < dist[adj[vertice.v][i]] && vertice.l != adj_cost[vertice.v][i].l){
				par x;				
				x.d= vertice.d +adj_cost[vertice.v][i].c;
				x.v = adj[vertice.v][i];
				x.l = adj_cost[vertice.v][i].l;
				q.push(x);
				//cout << "vertice: " << x.v << " custo: " << x.d << " letra: " << x.l << endl;
			}
		}
	}
}

int main(){
	int n;
	while(cin >> n, n!=0){
		for(int i=1; i < 4002; i++){
			for(int j=0; j<27; j++) vis[i][j] = false;
			adj[i].clear();
			adj_cost[i].clear();
			dist[i]=0x3f3f3f;
			vis2[i] = false;
		}
		mapa.clear();
		int j = 1;
		string ini,fim;
		cin >> ini >> fim;
		mapa[ini] = j++;
		mapa[fim] = j++;
		for(int i=0; i<n; i++){
			string nome1, nome2, palavra;
			cin >> nome1 >> nome2 >> palavra;
			if(mapa[nome1]==0) mapa[nome1] = j++;
			if(mapa[nome2]==0) mapa[nome2] = j++;
			adj[mapa[nome1]].push_back(mapa[nome2]);
			edge aux;
			aux.c = palavra.size();
			aux.l = palavra[0];
			adj_cost[mapa[nome1]].push_back(aux);
			adj[mapa[nome2]].push_back(mapa[nome1]);
			adj_cost[mapa[nome2]].push_back(aux);
		}
		calculaMenorDist(mapa[ini]);
		if(dist[mapa[fim]] == 0x3f3f3f) cout << "impossivel" << endl;
		else cout << dist[mapa[fim]] << endl;
	}
}
		









