#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define int long long 
#define pii pair<int,int>
#define ieps (int) 1e6
#define eps (int) 1e9
#define mp make_pair
#define pb push_back
int layer[ieps];
int dg[ieps] ;
vector<int> adj[ieps];
vector<int> adj2[ieps];
bool vis[ieps];
vector<int> s[ieps];
vector<int> t;
vector<int> solve(int i){
	vis[i] = true;
	vector<int> w;
	for(auto p : adj2[i]){
		if(vis[p]) continue;
		vector<int> t = solve(p);
		for(auto p : t){
			w.pb(p);
		}
	}
	sort(w.begin() , w.end());
	if(w != s[i]){
		puts("NO");
		exit(0);
	}
	w.pb(i);
	return w;
}
 
int32_t main(){
	/*ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	*/
	int n;
	cin>>n;
	for(int i = 1 ; i <= n; i++){
		int l;
		cin >>l;
		if(n == 1 && l == n){
			int x;
			cin>>x;
			cout<<"NO";
			return 0;
		}
		for(int j = 0 ; j < l ; j++){
			int x;
			cin>>x;
			dg[x]++;
			adj[i].pb(x);
			s[i].pb(x);
		}
		sort(s[i].begin() , s[i].end());
	}
	queue<int> q;
	int root = 0;
	for(int i = 1 ; i <= n ; i++) layer[i] = -1;
	for(int i = 1 ; i<=n;i++){
		if(dg[i] ==0) q.push(i) , layer[i] = 0 , root = i  ; 
	}
	set<pii> edges;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto p : adj[u]){
			dg[p]--;
			if(dg[p]==0 && layer[p] < layer[u] + 1){
				edges.insert(pii(u,p));
				q.push(p);
			}
			else if(dg[p] == 0 && layer[p] >= 0){
				cout<<"NO"<<endl;
				return 0;
			}
			layer[p] = layer[u] + 1;
		}
	}
	for(auto p :edges){
		adj2[p.F].pb(p.S);
		adj2[p.S].pb(p.F);
	}
	solve(root);
	for(int i = 1 ; i <= n ;i++){
		if(!vis[i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
 
	cout<<"YES"<<endl;
	for(auto p : edges){
		cout<<p.F<<" "<<p.S<<endl;
	}
}
