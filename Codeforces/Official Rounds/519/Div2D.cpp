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

int adj[10][112345];

int triangle(int n){
  return (n*(n+1))/2;
}

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  int v[n];
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  for(int i=1; i<m; i++){
    int lst = -1;
    for(int j=0; j<n; j++){
      int x;
      cin >> x;
      if(lst != -1) adj[i][lst] =x;
      lst = x;
    }
  }
  if(m == 1) {
    cout << triangle(n) << endl;
    return 0;
  }
  int sz = 1;
  int pointers[m];
  int ans = 0;
  for(int i =0; i<n; i++){
    if(i+1 < n){
      bool ok = true;
      for(int k=1; k<m; k++){
        if(adj[k][v[i]] != v[i+1]) ok = false;
      }
      if(!ok){
        ans += triangle(sz); 
        sz = 1;
      }
      else sz++;
    }
    else {
      ans += triangle(sz); 
    }
  }
  cout << ans << endl;
}

