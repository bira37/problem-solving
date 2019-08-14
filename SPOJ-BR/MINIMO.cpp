#include <bits/stdc++.h>


using namespace std;

int dist[112][112][112];

struct query{
	int u,v,k;
	query(int u, int v, int k) : u(u), v(v), k(k) {}
};

void relax(int i, int j, int k){
	dist[k][i][j] = min(dist[k-1][i][j], dist[k-1][i][k] + dist[k-1][k][j]);
}

int main(){
	int n,m,q,t = 1;
	while(cin >> n >> m){
		for(int k=0; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					if(i==j) dist[k][i][j] = 0;
					else dist[k][i][j] = 100000000;
				}
			}
		}
		for(int i=0; i<m; i++){
			int u,v,c;
			cin >> u >> v >> c;
			dist[0][u][v] = min(dist[0][u][v], c);
		}
		cin >> q;
		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					relax(i,j,k);
				}
			}
		}
		cout << "Instancia " << t++ << endl;
		for(int i=0; i<q; i++){
			int u,v,k;
			cin >> u >> v >> k;
			if(dist[k][u][v] == 100000000) cout << -1 << endl;
			else cout << dist[k][u][v] << endl;
		}
		cout << endl;
	}
}
