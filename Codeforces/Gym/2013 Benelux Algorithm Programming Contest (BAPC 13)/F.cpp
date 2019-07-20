#include <bits/stdc++.h>
 
using namespace std;
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define m0(x) memset((x), 0, sizeof(x))
#define m1(x) memset((x), -1, sizeof(x))
 
// #define DEBUG
#ifdef DEBUG
    #define debug(x) cout << x
#else
    #define debug(x) do {} while(0)
#endif
 
typedef pair<int,int> ii;
typedef vector< int > vi;
typedef vector< ii > vii;
 
int _gcd(int a, int b) { return b == 0 ? a : _gcd(b, a%b); }
int gcd(int a, int b) { return _gcd(abs(a), abs(b)); }
 
int32_t main() {
    DESYNC;
  int T;
  cin >> T;
  while(T--) {
    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
      cin >> a >> b;
    }
    cout << n-1 << endl;
  }
  
}
