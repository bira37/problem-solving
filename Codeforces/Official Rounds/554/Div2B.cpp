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

bool check(int x){
  while(x > 1){
    if(x%2) return false;
    x/=2;
  }
  return true;
}

int32_t main(){
  DESYNC;
  int x;
  cin >> x;
  vector<int> op;
  int cnt = 0;
  bool f = true;
  while(true){
    if(check(x+1)){
      cout << cnt << endl;
      for(int k : op) cout << k << " ";
      if(op.size() > 0) cout << endl;
      return 0;
    }
    cnt++;
    if(!f){
      x++;
    }
    else {
      for(int b = 20; b >=0; b--){
        if((1LL<<b) >= x) continue;
        if(x & (1LL << b)) continue;
        int val = (1LL << (b+1))-1;
        x ^= val;
        op.pb(b+1);
        break;
      }
    }
    f = !f;
  }
}

