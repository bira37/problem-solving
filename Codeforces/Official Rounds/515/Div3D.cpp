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

int n,m, k;
int v[212345];

bool check(int idx){
  int idm = 0, ido = idx, cur = k;
  while(ido < n){
    if(v[ido] <= cur){
      cur-= v[ido];
      ido++;
    }
    else {
      idm++;
      cur = k;
      if(idm == m) break;
    }
  }
  return ido == n;
}
  
int32_t main(){
  DESYNC;
  cin >> n >> m >> k;
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  
  int l = 0, r = n-1;
  int ans = -1;
  while(l <= r){
    int m = (l+r)>>1;
    if(check(m)){
      ans = m;
      r = m-1;
    }
    else l = m+1;
  }
  cout << n- ans << endl;  
}

