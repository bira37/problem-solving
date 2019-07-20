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
 
 
int n, m;
  
  string st[31];
  int pre[31][31];
  
  int dp[31][31];
  
int DP(int h, int w) {
 
  if(dp[h][w] != -1) return dp[h][w];
  if(h >= n || w <= -1) return 1;
  
  dp[h][w] = 1;
  for(int j = h; j < n; j++) {
    for(int k = 0; k <= w; k++) {
      int pr = 0;
      if(st[j][k] == '.' && pre[j][k] == 0 ) {
        dp[h][w] += DP(j+1, k-1);
      }
    }
  }
  
    //cout << "dp " << h << " " << w << " " << dp[h][w] <<  endl;
  return dp[h][w];
  
}
 
int32_t main(){
  DESYNC;
  
  cin >> n >> m;
  
  for(int i = 0; i < n; i++) {
    cin >> st[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(st[i][j] == 'B') {
        for(int k = i; k >= 0; k--) {
          for(int h = j; h >= 0; h--) {
            if(st[k][h] == 'R') {
              cout << "0" << endl;
              return 0;
            }
            st[k][h] = 'B';
          }
        }
      }
    }
  }
  
  for(int i = 0; i < 31; i++) {
    for(int j = 0; j < 31; j++) {
      dp[i][j] = -1;
    }
  }
  
    //cout << "bla" << endl;
 
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(st[i][j] == 'R') pre[i][j] = 1;
      else pre[i][j] = 0;
      if(i) pre[i][j] += pre[i-1][j];
      if(j) pre[i][j] += pre[i][j-1];
      if(i && j) pre[i][j] -= pre[i-1][j-1];
    }
  }
  
 
  
  cout << DP(0, m-1) << endl;
 
}
 
