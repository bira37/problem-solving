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
 
map<string, int> nid;
map<int, string> idn;
 
vi adj[512];
int vis[512];
 
/*int cyi = 0;
int cylen = INT_MAX;
vi cy;
 
int dii[512];
 
int dfs(int v, int di) {
  vis[v] = 1;
  int ret = 0;
  dii[v] = di;
  for(int ad : adj[v]) {
    if(vis[ad] == 0) {
      int cur = dfs(ad, di+1);
      if(cur == cyi) {
        ret = cur;
      }
    } else if(vis[ad] == 1) {
      int len = dii[v]-dii[ad]+1;
      if(len < cylen) {
        cylen = len;
        cyi = ad;
        cy.clear();
        //cy.pb(v);
        ret = cyi;
      }
    }
  }
  if(ret != 0) {
    cy.pb(v);
  }
  if(ret == v) ret = 0;
  vis[v] = 2;
  return ret;
}*/
 
int32_t main(){
  //DESYNC;
  
  int n;
  cin >> n;
  
  
  string file;
  for(int i = 1; i <= n; i++) {
    cin >> file;
    //cout << file << " " << i << endl;
    nid[file] = i;
    idn[i] = file;
  }
  
  
  
  int K;
  string imp;
  string ad;
  int id1, id2;
  for(int i = 1; i <= n; i++) {
    cin >> file >> K;
    id1 = nid[file];
    //cout << id1 <<" " << K << endl;
    cin.ignore();
    
    for(int k = 0; k < K; k++) {
      getline(cin, imp);
      //cout << imp << endl;
      //cin.ignore();
      
      int l = 0;
      int j, sz;
      
      for(sz = imp.size(), j = 0; j < sz; j++) {
         if(imp[j] == ' ') {
            l = j;
         }
         if(imp[j] == ',') {
            ad = imp.substr(l+1, (j-1)-(l+1)+1);
            //cout << ad << endl;
            id2 = nid[ad];
            adj[id1].pb(id2);
            //cout << " " << id1 << " " << id2 << endl;
         }
      }
      //ad = imp.substr(l, imp.size());
      //id2 = nid[ad];
      //adj[id1].pb(id2);
      
      ad = imp.substr(l+1, (j-1)-(l+1)+1);
      //cout << ad << endl;
      id2 = nid[ad];
      adj[id1].pb(id2);
      //cout << " " << id1 << " " << id2 << endl;
    }
  }
  
  int dist[n+1];
  
  int pa[n+1];
  memset(vis, 0, sizeof vis);
  queue<int> q;
  int cylen = INT_MAX;
  vi cy;
  for(int i = 1; i <= n; i++) {
    q.push(i);
    dist[i] = 0;
    memset(vis,0,sizeof vis);
    vis[i] = 1;
    pa[i] = 0;
    
    //cout << "i " << i << endl;
    
    while(!q.empty()) {
       int cur = q.front();
        //cout << cur << endl;
       q.pop();
       
       for(int ad : adj[cur]) {
        if(vis[ad] == 0) {
          vis[ad] = 1;
          dist[ad] = dist[cur]+1;
          q.push(ad);
          pa[ad] = cur;
        } else if(ad == i) {
          int len = dist[cur]+1;
          int aux = cur;
          if(len < cylen) {
            cy.clear();
            while(aux) {
             //cout<< aux << " ";
             cy.pb(aux);
             aux = pa[aux];
            }
            //cout << endl;
            cylen = len;
          }
        }
      }
    }
  }
  
  //cout << cylen << endl;
  if(cylen == INT_MAX) {
    cout << "SHIP IT" << endl;
  } else {
    reverse(cy.begin(), cy.end());
    for(int v : cy) {
      cout << idn[v] << " ";
    }
    cout << endl;
  }
  
  
  /*memset(vis, 0, sizeof vis);
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) dfs(i, 0);
  }
  
  //cout << cylen << endl;
  if(cylen == INT_MAX) {
    cout << "SHIP IT" << endl;
  } else {
    reverse(cy.begin(), cy.end());
    for(int v : cy) {
      cout << idn[v] << " ";
    }
    cout << endl;
  }*/
  
}
 
