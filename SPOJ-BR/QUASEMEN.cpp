#include <bits/stdc++.h>

using namespace std;

vector< pair<int,int> > adj[500];
int dist[500];
bool vis[500];
bool mv[500];

struct par{
	int first,second;
};

bool operator<(const par & a, const par & b){
	return a.second > b.second;
}

void csp(int x,int y){
	dist[x] = 0;
	priority_queue <par> q;
	par k;
	k.first = x;
	k.second = 0;
	q.push(k);
	while(!q.empty()){
		par v = q.top();
		q.pop();
		if(v.second > dist[v.first]) continue;
		dist[v.first] = v.second;
		//if(v.first == y) break;
		for(int i=0; i < adj[v.first].size(); i++){
			if(dist[v.first] + adj[v.first][i].second  < dist[adj[v.first][i].first]){
				par k;
				k.first = adj[v.first][i].first;
				k.second = dist[v.first] + adj[v.first][i].second;
				q.push(k);
			}
		}
	}
}

void dfs(int x,int y){
	vis[x] = true;
	int flag = false;
	for(int i=0; i< adj[x].size(); i++){
		if(dist[x] + adj[x][i].second == dist[adj[x][i].first]){
			if(!vis[adj[x][i].first] && adj[x][i].first != y){
				dfs(adj[x][i].first,y);
			}
			if(mv[adj[x][i].first]){
				mv[x] = true;
				adj[x].erase(adj[x].begin()+i);
				i--;
			}
		}
	}
}
				

int main(){
	int n,m;
	while(scanf("%d%d", &n, &m), n+m!=0){
		int ini,fim;
		scanf("%d%d", &ini, &fim);
		for(int i=0; i<n; i++){
			dist[i]= 0x3f3f3f3f;
			adj[i].clear();
			vis[i] = false;
			mv[i] = false;
		}
		for(int i=0; i<m; i++){
			int x,y,t;
			scanf("%d%d%d", &x, &y, &t);
			adj[x].push_back(make_pair(y,t));
		}
		csp(ini,fim);
		mv[fim] = true;
		dfs(ini,fim);
		for(int i=0; i < n; i++) dist[i] = 0x3f3f3f3f;
		csp(ini,fim);
		if(dist[fim] == 0x3f3f3f3f) printf("-1\n");
		else printf("%d\n",dist[fim]);
	}
}

