#include <bits/stdc++.h>

using namespace std;

int dist[101][2];
vector<int> adj[101];

void bfs(int n){
	queue< pair<int, int> > q;
	q.push(make_pair(n,0));
	dist[n][0]=0;
	while(!q.empty()){
		pair<int,int> vertice = q.front();
		q.pop();
		for(int i=0; i<adj[vertice.first].size(); i++){
			if(dist[adj[vertice.first][i]][!vertice.second] == 0x3f3f3f3f){
				dist[adj[vertice.first][i]][!vertice.second] = dist[vertice.first][vertice.second]+1;
				q.push(make_pair(adj[vertice.first][i],!vertice.second));
			}
		}
	}
}
			

int main(){
	int c,e;
	while(cin >> c >> e, c+e != 0){
		for(int i=1; i<=c; i++){
			dist[i][0]=0x3f3f3f3f;
			dist[i][1]=0x3f3f3f3f;
			adj[i].clear();
		}
		for(int i=0; i<e; i++){
			int x,y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int ini,fim,d;
		cin >> ini >> fim >> d;
		bfs(ini);
		if((d%2==0 && dist[fim][0] <= d) || (d%2==1 && dist[fim][1] <= d)) cout << "Yes, Teobaldo can travel." << endl;
		else cout << "No, Teobaldo can not travel."<< endl; 
	}
}
		
	

