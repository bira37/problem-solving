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

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

int32_t main(){
  DESYNC;
  int n,c,t;
  cin >> n >> c >> t;
  int v[n];
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  int l = 0, r = 1e9;
  int ans = -1;
  while(l <= r){
    int m = (l+r)>>1;

    //check m
    bool ok = true;
    int cur = 0;
    int qtd = 1;
    for(int i=0; i<n; i++){
      if((v[i]+t-1)/t > m){
        ok = false;
        break;
      }
      if((cur + v[i] + t-1)/t > m){
        cur = v[i];
        qtd++;
      }
      else cur += v[i];
    }
    if(qtd > c) ok = false;
    if(ok){
      ans = m;
      r = m-1;
    }
    else l = m+1;
  }
  cout << ans << endl;
}



