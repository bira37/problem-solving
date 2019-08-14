#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

vector<ii> adj[250];
int dist[250];
int n,m,c,k;

struct par{
	int first,second;
};

bool operator<(const par & a, const par & b){
	return a.second > b.second;
}


void csp(int x){
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
		for(int i=0; i < adj[v.first].size(); i++){
			if(v.first >= c || (v.first < c && v.first+1 == adj[v.first][i].first)){
				if(dist[v.first] + adj[v.first][i].second  < dist[adj[v.first][i].first]){
					par k;
					k.first = adj[v.first][i].first;
					k.second = dist[v.first] + adj[v.first][i].second;
					q.push(k);
				}
			}
		}
	}
}

int main(){
	while(cin >> n >> m >> c >> k, n && m && c && k){
		for(int i=0; i<n; i++){
			adj[i].clear();
			dist[i] = 0x3f3f3f3f;
		}
		for(int i=0; i<m; i++){
			int x,y,t;
			cin >> x >> y >> t;
			adj[x].push_back(ii(y,t));
			adj[y].push_back(ii(x,t));
		}
		csp(k);
		cout << dist[c-1] << endl;
	}
}

