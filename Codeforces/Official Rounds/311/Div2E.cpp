#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
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
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
bool dp[5123][5123];
string s;
string ans;
 
namespace Trie{
 
  struct node {
    node *adj[2];
    int cnt = 0;
    node(){
      for(int i=0; i<2; i++) adj[i] =  NULL;
      cnt = 0;
    }
  };
 
  struct Tree{
 
    node *t;
    
    Tree(){
      t = new node();
    }
    
    void add(int idx){
      node *cur = t;
      for(int i = idx; i < s.size(); i++){
        if(s[i] == 'a'){
          if(!cur->adj[0]) cur->adj[0] = new node();
          cur = cur->adj[0];
          cur->cnt += dp[idx][i];
        }
        else {
          if(!cur->adj[1]) cur->adj[1] = new node();
          cur = cur->adj[1];
          cur->cnt += dp[idx][i];
        }
      }
    }
    
    void query(int k){
      node *cur = t;
      int lst;
      while(k > 0 && cur){
        //cout << "cur ans = " << ans << endl;
        //cout << "k is " << k << endl;
        lst = cur->cnt;
        if(cur->adj[0]) lst -= cur->adj[0]->cnt;
        if(cur->adj[1]) lst -= cur->adj[1]->cnt;
        //if(cur->adj[0]) cout << "desceding to a " << cur->adj[0]->cnt << endl;
        //if(cur->adj[1]) cout << "descending to b " << cur->adj[1]->cnt << endl;
        if(lst >= k){
          return;
        }
        k -= lst;
        if(cur->adj[0] && cur->adj[0]->cnt >= k){
          ans += 'a';
          cur = cur->adj[0];
        }
        else {
          if(cur->adj[0]) k -= cur->adj[0]->cnt;
          if(cur->adj[1] && cur->adj[1]->cnt < k) k -= cur->adj[1]->cnt;
          cur = cur->adj[1];
          ans += 'b';
        }
      }
    }
 
    void process(node * cur){
      if(cur->adj[0]){
        process(cur->adj[0]);
        cur->cnt += cur->adj[0]->cnt;
      }
      if(cur->adj[1]){
        process(cur->adj[1]);
        cur->cnt += cur->adj[1]->cnt;
      }
    }
 
     
  };
  
}
 
int32_t main(){
  DESYNC;
  Trie::Tree trie; 
  cin >> s;
  int k;
  cin >> k;
  for(int i=0; i<s.size(); i++){
    for(int j=0; j<s.size(); j++) dp[i][j] = false;
  }
  for(int i=0; i<s.size(); i++){
    int l = i, r = i;
    while(l >= 0 && r < s.size()){
      bool ok = true;
      if(s[l] != s[r]) ok = false;
      if(l + 2 <= i && r-2 >= i && !dp[l+2][r-2]) ok = false;
      dp[l][r] = ok;
      l--, r++;
    }
    l = i, r = i+1;
    while(l >= 0 && r < s.size()){
      bool ok = true;
      if(s[l] != s[r]) ok = false;
      if(l + 2 <= i && r-2 >= i && !dp[l+2][r-2]) ok = false;
      dp[l][r] = ok;
      l--, r++;
    }
    l = i-1, r = i;
    while(l >= 0 && r < s.size()){
      bool ok = true;
      if(s[l] != s[r]) ok = false;
      if(l + 2 <= i && r-2 >= i && !dp[l+2][r-2]) ok = false;
      dp[l][r] = ok;
      l--, r++;
    }
  }
  for(int i=0; i<s.size(); i++){
    trie.add(i);
  }
  trie.process(trie.t);
  trie.query(k);
  cout << ans << endl;
}
 
