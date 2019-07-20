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
#define INF 1e9
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int dp[4000];
int v[20];
int n,t;
 
int32_t main(){
  DESYNC;
  int test;
  cin >> test;
  for(int i=0; i<test; i++){
    cin >> n >> t;
    for(int i=0; i<n; i++){
      cin >> v[i];
    }
    for(int i=0; i<4000; i++) dp[i] = INF;
    queue< ii > q;
    dp[0] = 0;
    q.push(ii(0, 0));
    while(!q.empty()){
      int cur = q.front().ff;
      int sm = q.front().ss;
      q.pop();
      if(dp[cur] < sm) continue;
      for(int i=0; i<n; i++){
        int nxt = min(3600LL, max(0LL, cur + v[i]));
        if(dp[nxt] > sm+1){
          dp[nxt] = sm+1;
          q.push(ii(nxt, sm+1));
        }
      }
    }
    for(int i=t; i<4000; i++){
      if(dp[i] < INF){
        cout << dp[i] << " " << i - t << endl;
        break;
      }
    }
  }   
}
 
