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
  string s,p;
  cin >> s >> p;
  int n = s.size();
  vector< vector<int> > dp(n+1 , vector<int>(n+1, 0));
  vector<int> nxt(n), del(n);
  for(int i=0; i<n; i++){
    int cur = i;
    int pcur = 0;
    for(; cur < n; cur++){
      if(p[pcur] == s[cur]) pcur++;
      if(pcur == p.size()) break;
    }
    nxt[i] = -1;
    del[i] = -1;
    if(pcur == p.size()){
      nxt[i] = cur+1;
      del[i] = (cur - i + 1 - p.size());
    }
  }
  for(int i=0; i<n; i++){
    for(int j = 0; j<=i; j++){
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
      if(nxt[i] != -1){
        dp[nxt[i]][j+del[i]] = max(dp[nxt[i]][j+del[i]], dp[i][j]+1);
      }
    }
  }
  for(int i=0; i<=n; i++) cout << dp[n][i] << " ";
  cout << endl;
}

