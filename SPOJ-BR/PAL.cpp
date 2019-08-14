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
  int n;
  int t = 1;
  while(cin >> n, n != 0){
    cout << "Teste " << t++ << endl;
    string s;
    cin >> s;
    bool pal[2123][2123];
    for(int i=0; i<2123; i++){
      for(int j=0; j<2123; j++) pal[i][j] = false;
    }
    s = "0"+s;
    for(int i=1; i<=n; i++){
      pal[i][i] = true;
      int l = i-1, r = i+1;
      while(l >= 0 && r <= n && s[l] == s[r]) pal[l--][r++] = true;
      l = i-1, r = i;
      while(l >= 0 && r <= n && s[l] == s[r]) pal[l--][r++] = true;
      l = i, r = i+1;
      while(l >= 0 && r <= n && s[l] == s[r]) pal[l--][r++] = true;
    }
    int dp[n+1];
    for(int i=0; i<=n; i++) dp[i] = INF;
    dp[0] = 0;
    for(int i=1; i<=n; i++){
      for(int k=0; k<i; k++){
        //cout << k << " " << dp[k] << endl;
        if(pal[k+1][i] && dp[k] != INF) dp[i] = min(dp[i], dp[k] + 1);
      }
    }
    cout << dp[n] << endl << endl;
  }
}


