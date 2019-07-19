#include <bits/stdc++.h>
#define int long long
using namespace std;
 
map< pair<int,int> , int> id;
 
vector<int> adj[312345];
vector<int> adjc[312345];
int p[312345];
int peso[312345];
int dist[312345];
bool vis[312345];
 
struct info{
	int v;
	int d;
	info() {}
	info(int v, int d) : v(v), d(d) {} 
};
 
bool operator<(const info & a, const info & b) {
		return !(a.d < b.d);
	}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=0; i<=n; i++){
		dist[i] = (int)1e16;
		vis[i] = false;
		p[i] = -1;
		peso[i] = (int)1e16;
	}
	for(int i=0; i<m; i++){
		int u,v,c;
		cin >> u >> v >> c;
		adj[u].push_back(v);
		adj[v].push_back(u);
		adjc[u].push_back(c);
		adjc[v].push_back(c);
		id[make_pair(u,v)] = i+1;
		id[make_pair(v,u)] = i+1;
	}
	int u;
	cin >> u;
	priority_queue<info> pq;
	pq.push(info(u, 0));
	p[u] = -1;
	dist[u] = 0;
	vector<int> ans;
	int weight = 0;
	while(!pq.empty()){
		info cur = pq.top();
		pq.pop();
		for(int i=0; i<adj[cur.v].size(); i++){
			int v = adj[cur.v][i];
			int c = adjc[cur.v][i];
			if(dist[v] > dist[cur.v] + c || (dist[v] == dist[cur.v] + c && c < peso[v])){
				dist[v] = dist[cur.v] + c;
				p[v] = cur.v;
				peso[v] = c;
				pq.push(info(v, dist[v]));
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(peso[i] != (int)1e16){
			weight += peso[i];
			ans.push_back(id[make_pair(i, p[i])]);
		}
	}
	cout << weight << endl;
	sort(ans.begin(), ans.end());
	for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
	if(ans.size() > 0) cout << endl;
}
