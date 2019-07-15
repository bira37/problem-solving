#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define M 1000000007
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second
#define int long long

using namespace std;
using namespace __gnu_pbds;

//////////////////////////////////////////////STL - Ordered Set////////////////////////////////////////////
typedef tree<
int, //change for pair<int,int> to use like multiset
null_type,
less<int>, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int differ = 0;
//////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////

vector<int> adj[212345];
bitset<212345> vis;
int p[212345];
vector<int> v;

void dfs(int u){
  vis[u] = true;
  v.push_back(u);
  for(int vertex : adj[u]){
    if(!vis[vertex]) dfs(vertex);
  }
} 

int32_t main(){

  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  
  vis.reset();
  int n,m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  int ans = 0;
  for(int i=1; i<=n; i++){
    if(!vis[i]){
      v.clear();
      dfs(i);
      bool ok = true;
      for(int vertex : v){
        if(ok == false) break;
        if(adj[vertex].size() != 2) ok = false;
      }
      ans += ok;
    }
  }
  
  cout << ans << endl;
}