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
int ans[212345];

int32_t main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  int v[n];
  map<int, vector<int> > m;
  for(int i=0; i<n; i++){
    ans[i] = 0;
    cin >>v[i];
  }
  for(int i=0; i<n; i++){
    int lig = v[i]-1;
    ans[i] = 1;
    for(int x : m[lig]){
      adj[x].pb(i);
      ans[i] = max(ans[i], ans[x]+1);
    }
    m[v[i]].push_back(i);
    m[lig].clear();
  }
  int best = 0;
  int start = 0;
  for(int i=0; i<n; i++){
    if(best < ans[i]){
      best = max(best, ans[i]);
      start = i;
    }
  }
  cout << best << endl;
  vector<int> print;
  print.pb(start);
  int want = v[start]-1;
  best--;
  for(int i=start-1; i>=0; i--){
    if(ans[i] == best && v[i] == want){
      print.pb(i);
      best--;
      want--;
    }
  }
  reverse(print.begin(), print.end());
  for(int x : print) cout << x+1 << " ";
  cout << endl;
}