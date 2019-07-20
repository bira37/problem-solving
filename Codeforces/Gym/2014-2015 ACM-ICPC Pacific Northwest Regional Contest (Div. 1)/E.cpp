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
 
string st;
 
bool checkhill() {
  bool fall = false;
  for(int i = 1; i < st.size(); i++) {
    if(st[i] > st[i-1]) {
      if(fall) return false;
    } else {
      if(st[i] < st[i-1]) fall = true;
    }
  }
  return true;
}
 
int dp[71][2][2][10];
 
int DP(int d, int m, int f, int l) {
//  cout << st << endl;
  //cout << d << " " << m << " " << f << " " << l << endl;
  if(dp[d][m][f][l] != -1) return dp[d][m][f][l];
  if(d == st.size()) return 1;
  
  dp[d][m][f][l] = 0;
  if(!m) {
    if(!f) {
      // Não é menor nem caiu
      for(int i = 0; i < st[d]-'0'; i++) {
        dp[d][m][f][l] += DP(d+1, 1, (i < l ? 1 : 0), i);
      }
      dp[d][m][f][l] += DP(d+1, 0, (st[d]-'0') < l ? 1 : 0, st[d]-'0');
    } else {
      // Não é menor e caiu
      if((st[d]-'0') <= l) {
        // digito atual <= last
        for(int i = 0; i < st[d]-'0'; i++) {
          dp[d][m][f][l] += DP(d+1, 1, 1, i);
        }
        dp[d][m][f][l] += DP(d+1, 0, 1, st[d]-'0');
      } else {
        // last < digito atual
        for(int i = 0; i <= l; i++) {
          dp[d][m][f][l] += DP(d+1, 1, 1, i);
        }
      }
    }
  } else {
    if(!f) {
      // Já é menor, mas não caiu
      for(int i = 0; i < l; i++) {
        dp[d][m][f][l] += DP(d+1, 1, 1, i);
      }
      for(int i = l; i <= 9; i++) {
        dp[d][m][f][l] += DP(d+1, 1, 0, i);
      }
    } else {
      // Já é menor, e já caiu
      for(int i = 0; i <= l; i++) {
        dp[d][m][f][l] += DP(d+1, 1, 1, i);
      }
    }
  }
  
  return dp[d][m][f][l];
}
 
int32_t main(){
  DESYNC;
  
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    cin >> st;
    if(!checkhill()) {
      cout << -1 << endl;
      continue;
    }
    
    memset(dp, -1, sizeof dp);
    
    cout << DP(0, 0, 0, 0)-1 << endl;
  }
}
 
