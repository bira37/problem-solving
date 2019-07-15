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
#define INF 2e18+10
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

int lcm(int a, int b){
  return a*(b/gcd(a,b));
}

int32_t main(){
  DESYNC;
  int x,y;
  cin >> x >> y;
  if(x == y){
    cout << 0 << endl;
    return 0;
  }
  if(y > x) swap(x,y);
  //gcd(x-y, y+k)
  int ans = INF;
  int bst = INF;
  for (int d = 1; d <= sqrt(x-y); d++){
    if((x-y)%d == 0){
      //do for d
      int ny = y + (d - (y%d))%d;
      int l = lcm(x-y, ny); 
      if(l < bst || (bst == l && ans > (d - (y%d))%d)){
        bst = l;
        ans = (d - (y%d))%d;
      }
      //do for d2
      int d2 = (x-y)/d;
      ny = y + (d2 - (y%d2))%d2;
      l = lcm(x-y, ny); 
      if(l < bst || (bst == l && ans > (d2 - (y%d2))%d2)){
        bst = l;
        ans = (d2 - (y%d2))%d2;
      }
    }
  }
  cout << ans << endl;
}

