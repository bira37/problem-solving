#include <bits/stdc++.h>
 
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
struct node{
  map<char, node*> adj;
  int cnt = 0;
};
 
int ans[112345];
 
void insert(string & s, node *r){
  node * cur = r;
  int sz = 0;
  for(int i=(int)(s.size())-1; i>=0; i--){
    sz++;
    char c = s[i];
    if(!cur->adj.count(c)){
      cur->adj[c] = new node();
    }
    cur = cur->adj[c];
    cur->cnt++;
    ans[sz] = max(ans[sz], cur->cnt);
  }
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    node * root = new node();
    int n, q;
    cin >> n >> q;
    int mx = 0;
    string v[n];
    for(int i=0; i<n; i++){
      cin >> v[i];
      mx = max(mx, (int)v[i].size());
    }
    for(int i=0; i<=mx; i++) ans[i] = 0;
    for(int i=0; i<n; i++){
      insert(v[i], root);
    }
    while(q--){
      int x;
      cin >> x;
      cout << ans[x] << endl;
    }
  }
}
 
