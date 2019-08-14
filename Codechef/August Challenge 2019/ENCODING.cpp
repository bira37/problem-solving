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

inline int mod(int n, int m = M){ int ret = n%m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

int dp[112345][2][10];
int dp2[112345][2][10];

string s,r;
int sz;
int pot[112345];

int solve(int n, bool equal, int lst){
  if(n == 0){
    dp[n][equal][lst] = 1;
  }
  if(dp[n][equal][lst] != -1) return dp[n][equal][lst];
  
  dp[n][equal][lst] = 0;
  if(equal){
    for(int i=0; i<=s[sz-n]-'0'; i++){
      dp[n][equal][lst] = mod(dp[n][equal][lst] + solve(n-1, (s[sz-n]-'0' == i && equal ? true : false), i));
    }
  }
  else {
    for(int i=0; i<=9; i++){
      dp[n][equal][lst] = mod(dp[n][equal][lst] + solve(n-1, equal, i));
    }
  }
  //cout << "dp[" << n << "][" << equal << "][" << lst << "] = " << dp[n][equal][lst] << endl;  
  return dp[n][equal][lst];
}

int go(int n, bool equal, int lst){
  if(n == 0) return 0;
  if(dp2[n][equal][lst] != -1) return dp2[n][equal][lst];
  
  dp2[n][equal][lst] = 0;
  
  if(equal){
    for(int i=0; i<=s[sz-n]-'0'; i++){
      //cout << "running " << i << endl;
      int A = go(n-1, (s[sz-n]-'0' == i && equal ? true : false), i);
      int B = dp[n-1][(s[sz-n]-'0' == i && equal ? true : false)][i];
      B = mod(B*pot[n-1]);
      B = mod(B*i);
      B = mod(B*(lst != i));
      A = mod(A+B);
      dp2[n][equal][lst] = mod(dp2[n][equal][lst] + A);
      //cout << "val = " << dp[n-1][(s[sz-n]-'0' == i && equal ? true : false)][i]*pot[n-1]*i*(lst != i) << endl;
    }
  }
  else {
    for(int i=0; i<=9; i++){
      int A = go(n-1, equal, i);
      int B = dp[n-1][equal][i];
      B = mod(B*pot[n-1]);
      B = mod(B*i);
      B = mod(B*(lst != i));
      A = mod(A+B);
      dp2[n][equal][lst] = mod(dp2[n][equal][lst] + A);
    }
  }
  //cout << "dp2[" << n << "][" << equal << "][" << lst << "] = " << dp2[n][equal][lst] << endl;  
  return dp2[n][equal][lst];
}
      
int f(string s){
  int n = s.size();
  reverse(s.begin(), s.end());
  char lst = '0';
  int ans = 0;
  for(int i=n-1; i>=0; i--){
    if(lst != s[i]) ans = mod(ans + mod(pot[i]*(s[i]-'0')));
    lst = s[i];
  }
  return ans;
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int nl, nr;
    cin >> nl >> s;
    cin >> nr >> r;
    pot[0] = 1;
    for(int i=1; i<112345; i++) pot[i] = mod(pot[i-1]*10LL);
    //do for l
    sz = s.size();
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);
    solve(nl, true, 0);
    int ans1 = go(nl, true, 0);
    
    //do for r
    swap(s,r);
    swap(nl, nr);
    sz = s.size();
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);
    solve(nl, true, 0);
    int ans2 = go(nl, true, 0);
    cout << ((ans2-ans1+f(r))%M + M)%M << endl;
  }
}
  


