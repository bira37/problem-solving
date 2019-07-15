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
  int t;
  cin >> t;
  while(t--){
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    int n;
    cin >> n;
    while(n--){
      int x;
      cin >> x;
      if(x%3 == 0) cnt0++;
      else if(x%3 == 1) cnt1++;
      else cnt2++;
    }
    int ans = cnt0;
    int tira = min(cnt1, cnt2);
    ans += tira;
    cnt1 -= tira;
    cnt2 -= tira;
    ans += cnt1/3;
    ans += cnt2/3;
    cout << ans << endl;
  }
}

