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

int32_t main(){
  DESYNC;
  int t = 1;
  int n;
  while(cin >> n){
    bool dp[1001];
    cout << "Case #" << t++ << ":";
    for(int i=0; i<1001; i++){
      dp[i] = false;
    }
    dp[0] = true;
    bool ok = true;
    int lst = -1;
    for(int i=0; i<n; i++){
      int x;
      cin >> x;
      cout << " " << x;
      if(lst >= x) ok = false;
      lst = x;
      if(x <= 1000 && dp[x]) ok = false;
      for(int j = 1000; j>=x && j-x >= 0; j--){
        dp[j] |= dp[j-x];
      }
    }
    if(ok) cout << endl << "This is an A-sequence." << endl;
    else cout << endl << "This is not an A-sequence." << endl;
  }
  
}


