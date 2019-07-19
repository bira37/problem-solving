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
#define M 998244353
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int v[n];
  int cnt[11];
  for(int i=0; i<11; i++){
    cnt[i] = 0;
  }
  for(int i=0; i<n; i++){
    cin >> v[i];
    int x = v[i];
    int a = 0;
    while(x > 0){
      a++;
      x/=10;
    }
    cnt[a]++;
  }
  int ans = 0;
  for(int sz = 1; sz < 11; sz++){
    for(int i=0; i<n; i++){
      int cur = sz;
      int pot = 1;
      int x = v[i];
      while(x > 0){
        int d = x%10;
        x/=10;
        ans = mod(ans + mod(d*cnt[sz], M)*pot, M);
        if(cur > 0){
          pot = mod(pot*100LL, M);
          cur--;
        }
        else pot = mod(10LL*pot, M);
      }
      
      cur = sz-1;
      pot = 10;
      x = v[i];
      while(x > 0){
        int d = x%10;
        x/=10;
        ans = mod(ans + mod(d*cnt[sz], M)*pot, M);
        if(cur > 0){
          pot = mod(pot*100LL, M);
          cur--;
        }
        else pot = mod(10LL*pot, M);
      }
    }
  }
  cout << ans << endl;
    
}
 
