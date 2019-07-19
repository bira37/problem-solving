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
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

double fat[11234567+1];

int32_t main(){
  DESYNC;
  fat[0] = 0;
  for(int i=1; i<=11234567; i++){
    fat[i] = fat[i-1] + log(i);
  }
  int t;
  cin >> t;
  while(t--){
    int a; cin >> a;
    int l = 0, r = 11234567;
    int ans = 0;
    while(l <= r){
      int m = (l+r)>>1;
      if(fat[m] < m*log(a)){
        l = m+1;
      }
      else{
        ans = m;
        r = m-1;
      }
    }
    cout << ans << endl;
  }
}


