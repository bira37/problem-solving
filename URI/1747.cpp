#include <bits/stdc++.h>

using namespace std;

set<int> s;
vector<int> adj[112345];
int candy[112345];
set<int> q[112345];

void dfs(int u, int mdc){
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		int m = __gcd(mdc, candy[v]);
		if(q[v].find(m) != q[v].end()) continue;
		q[v].insert(m);
		s.insert(m);
		dfs(v, m);
	}
}

int main(){
	int n,m;
    while(scanf("%d %d", &n, &m) == 2){
    	s.clear();
    	for(int i=1; i<=n; i++){
    		adj[i].clear();
    		scanf("%d", candy+i);
    	}
    	for(int i=0; i<m; i++){
    		int u,v;
    		scanf("%d %d", &u, &v);
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	//s.insert(1);
    	for(int i=1; i<=n; i++){
    	    q[i].insert(candy[i]);
    	    s.insert(candy[i]);
    		dfs(i, candy[i]);
    	}
    	printf("%d\n", (int)s.size());
    }
}
