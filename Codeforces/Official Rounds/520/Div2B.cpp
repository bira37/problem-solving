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
  vector< ii > f;
  int n;
  cin >> n;
  for(int i=2; i<=sqrt(n); i++){
    if(n%i == 0){
      int cnt =0;
      while(n%i == 0){
        cnt++;
        n/=i;
      }
      f.pb(ii(i, cnt));
    }
  }
  if(n != 1) f.pb(ii(n, 1));
  int ans = 1;
  int cnt = 0;
  int cu = 0;
  for(auto p : f){
    ans *= p.ff;
    int need = 0;
    if(p.ss <= 1) cnt = max(cnt, 0LL), need = 1;
    else if(p.ss <= 2) cnt = max(cnt, 1LL), need = 2;
    else if(p.ss <= 4) cnt = max(cnt, 2LL), need = 4;
    else if(p.ss <= 8) cnt = max(cnt, 3LL), need = 8;
    else if(p.ss <= 16) cnt = max(cnt, 4LL), need = 16;
    else if(p.ss <= 32) cnt = max(cnt, 5LL), need = 32;
    cu = max(need, cu);
  }
  bool merda = false;
  for(auto p : f){
    if(p.ss < cu) merda = true;
  }
  cout << ans << " " << cnt + merda << endl;
  
}

