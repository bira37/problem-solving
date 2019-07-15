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
  string s;
  cin >> s;
  string t = s;
  int n = s.size();
  int ans = INF;
  bool dp[n][n];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) dp[i][j] = false;
  }
  for(int i=0; i<n; i++){
    int l = i, r = i;
    while(l >= 0 && r < n && s[l] == s[r]){
      dp[l][r] = true;
      l--, r++;
    }
    
     l = i, r = i+1;
    while(l >= 0 && r < n && s[l] == s[r]){
      dp[l][r] = true;
      l--, r++;
    }
    
    l = i-1, r = i;
    while(l >= 0 && r < n && s[l] == s[r]){
      dp[l][r] = true;
      l--, r++;
    }
    
     l = i-1, r = i+1;
    while(l >= 0 && r < n && s[l] == s[r]){
      dp[l][r] = true;
      l--, r++;
    }
  }
  if(n%2 == 0){
    int r = n-1;
    for(int i = r; i >= n/2; i--){
      //cout << i << endl;
      if(dp[0][i-1] && dp[i][r] && (r-i+1)%2 == 0){
        string test = s.substr(i + (r-i+1)/2, (r-i+1)/2) + s.substr(0, i + (r-i+1)/2);
        //cout << test << endl;
        if(test != t) ans = min(ans, 1LL);
      }
    }
  }
  for(int i=0, j = n-1; i < j; i++, j--){
    //test
    reverse(s.begin(), s.begin()+i+1);
    reverse(s.begin()+j, s.end());
    ///cout << i << " " << j << " " << s << endl;
    if(s != t){
      if(i+1 != j) ans = min(ans, 2LL);
      else ans = min(ans, 1LL);
    }
    reverse(s.begin(), s.begin()+i+1);
    reverse(s.begin()+j, s.end());
  }
  cout << (ans >= INF ? "Impossible" : to_string(ans)) << endl;
}

