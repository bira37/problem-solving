#include <bits/stdc++.h>
#define double long double
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
#define M 998244353
const double PI = acos(-1);
 
using namespace std;
 
inline long long mod(long long n, long long m){ long long ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
int32_t main(){
  DESYNC;
  int n,m,a,b;
  cin >> n >> m >> a >> b;
  long long g;
  int mat[n][m];
  long long x,y,z;
  cin >> g >> x >> y >> z;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      mat[i-1][j-1] = g;
      g = mod(g*x + y, z);
    }
  } 
  vector<int> nxt[n];
  deque<ii> q;
  for(int i=0; i<n; i++){
    q.clear();
    for(int j=0; j<b; j++){
      while(q.size() > 0 and q.front().ss <= j-b) q.pop_front();
      while(q.size() > 0 and q.back().ff >= mat[i][j]) q.pop_back();
      q.push_back(ii(mat[i][j], j));
    }
    nxt[i].pb(q.front().ff);
    //cout << q.front().ff << " ";
    for(int j=b; j<m; j++){
      while(q.size() > 0 and q.front().ss <= j-b) q.pop_front();
      while(q.size() > 0 and q.back().ff >= mat[i][j]) q.pop_back();
      q.push_back(ii(mat[i][j], j));
      nxt[i].pb(q.front().ff);
      //cout << q.front().ff << " ";
    }
    //cout << endl;
  }
  //cout << endl;
  q.clear();
  vector<int> ans[nxt[0].size()];
  for(int j=0; j<nxt[0].size(); j++){
    q.clear();
    for(int i=0; i<a; i++){
      while(q.size() > 0 and q.front().ss <= i-a) q.pop_front();
      while(q.size() > 0 and q.back().ff >= nxt[i][j]) q.pop_back();
      q.push_back(ii(nxt[i][j], i));
    }
    ans[j].pb(q.front().ff);
    //cout << q.front().ff << " ";
    for(int i=a; i<n; i++){
      while(q.size() > 0 and q.front().ss <= i-a) q.pop_front();
      while(q.size() > 0 and q.back().ff >= nxt[i][j]) q.pop_back();
      q.push_back(ii(nxt[i][j], i));
      ans[j].pb(q.front().ff);
      //cout << q.front().ff << " ";
    }
    //cout << endl;
  }
  long long tot = 0;
  for(int j=0; j<nxt[0].size(); j++){
    for(int i=0; i<ans[j].size(); i++) tot += (long long)(ans[j][i]);
  }
  cout << tot << endl;
    
}
 
