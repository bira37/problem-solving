#include <bits/stdc++.h>

#define int unsigned long long
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

int legendre(int n, int p){
  int cur = p;
  int cnt = 0;
  while(cur <= n){
    cnt += n/cur;
    if(cur > n/p) break;
    cur *=p;
  }
  return cnt;
}

vector< ii > f;

int32_t main(){
  DESYNC;
  int n, k;
  cin >> n >> k;
  f.clear();
  for(int i=2; i<=sqrt(k); i++){
    if(k%i == 0){
      f.push_back(ii(i, 0));
      while(k%i == 0){
        k/=i;
        f.back().ss++;
      }
    }
  }
  if(k != 1) f.push_back(ii(k, 1));
  int ans = ULLONG_MAX;
  for(ii p : f){
    ans = min(legendre(n, p.ff)/p.ss, ans);
  }
  cout << ans << endl;
}

