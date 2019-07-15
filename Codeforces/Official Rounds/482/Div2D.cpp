#include <bits/stdc++.h>

#define int long long
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

using namespace std;

inline int mod(int n){ return (n%1000000007); }

struct tnode {
  tnode *adj[2];
  int min_val;
  tnode(){
   min_val = INT_MAX;
   adj[0] = adj[1] = NULL;
  }
};

struct Trie{

  tnode *t;
  
  void init(){
    t = new tnode();
  }
  
  void add(int x){
    tnode *curr = t;
    curr->min_val = min(curr->min_val, x);
    for(int i=20; i>=0; i--){
      if((1<<i) & x){
        if(curr->adj[1] == NULL) curr->adj[1] = new tnode();
        curr = curr->adj[1];
        curr->min_val = min(curr->min_val, x);
      }
      else {
        if(curr->adj[0] == NULL) curr->adj[0] = new tnode();
        curr = curr->adj[0];
        curr->min_val = min(curr->min_val, x);
      }
    }
  }
  
  int query(int x, int s){
    tnode *curr = t;
    int ans = 0;
    if(curr->min_val > s) return -1;
    for(int i=20; i>=0; i--){
      bool bit = (1<<i) & x;
      if(curr->adj[!bit] != NULL && curr->adj[!bit]->min_val <= s){
        curr = curr->adj[!bit];
        if(!bit) ans |= (1<<i);
      }
      else {
        if(bit) ans |= (1<<i);
        curr = curr->adj[bit];
      }
    }
    return ans; 
  } 

};

vector<int> divi[112345];

Trie trie[112345];

void init(){
  for(int i=1; i<=100000; i++){
    for(int j = i; j<=100000; j+=i){
      divi[j].pb(i);
    }
    trie[i].init();
  }
}

bitset<112345> vis;

int32_t main(){
	DESYNC;
	int q;
	init();
	cin >> q;
	vis.reset();
	while(q--){
	  int op;
	  cin >> op;
	  if(op == 1){
	    int x;
	    cin >> x;
	    if(vis[x]) continue;
	    vis[x] = true;
	    for(int d : divi[x]) trie[d].add(x);
	  }
	  else {
	    int x,k,s;
	    cin >> x >> k >> s;
	    if((x%k) != 0) cout << -1 << endl;
	    else cout << trie[k].query(x, s - x) << endl;
	  }
	}
}

