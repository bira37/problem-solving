#include <bits/stdc++.h>

#define int long long
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
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int cross(ii a, ii b){
  return abs(a.ff*b.ss - a.ss*b.ff);
}

int area(ii a, ii b, ii c){
  ii v1 = mp(a.ff - b.ff, a.ss - b.ss);
  ii v2 = mp(a.ff - c.ff, a.ss - c.ss);
  return cross(v1, v2);
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  ii v[n+n];
  for(int i=0; i<n; i++){
    cin >> v[i].ff >> v[i].ss;
    v[i+n] = v[i];
  }
  
  int cur = 0;
  int ans = 0;
  for(int i=0; i<n; i++){
    if(cur <= i) cur = i+1;
    while(cur < 2*n-1 && area(v[i], v[i+1], v[cur]) <= area(v[i], v[i+1], v[cur+1])){
      cur++;
    }
    int sz = cur - i + 1;
    sz -= 2;
    ans += (sz*(sz-1))/2;
  }
  cout << (n*(n-1)*(n-2))/6 - ans << endl;
  
}


