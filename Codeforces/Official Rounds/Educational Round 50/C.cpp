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

int dp[20][5][2];

int count(string s, int i, int cnt, bool f){
  if(cnt < 0) return 0;
  if(i == s.size()){
    return (cnt == 0);
  }
  if(dp[i][cnt][f] != -1) return dp[i][cnt][f];
  dp[i][cnt][f] = 0;
  //go to 0
  dp[i][cnt][f] += count(s, i+1, cnt, f || (s[i] != '0'));
  //go to others
  if(f){
    for(int d = '1'; d <= '9'; d++){
      dp[i][cnt][f] += count(s, i+1, cnt-1, f);
    }
  }
  else {
    for(int d = '1'; d <= s[i]; d++){
      dp[i][cnt][f] += count(s, i+1, cnt-1, s[i] != d);
    }
  }
  return dp[i][cnt][f];
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int l, r;
    cin >> l >> r;
    l--;
    string a = to_string(l);
    string b = to_string(r);
    for(int i=0; i<20; i++){
      for(int j=0; j<5; j++){
        for(int k =0; k<2; k++) dp[i][j][k] = -1;
      }
    }
    int ans1 = count(b, 0, 3, false) + count(b, 0, 2, false) + count(b, 0, 1, false) + count(b, 0, 0, false);
    for(int i=0; i<20; i++){
      for(int j=0; j<5; j++){
        for(int k =0; k<2; k++) dp[i][j][k] = -1;
      }
    }
    int ans2 = count(a, 0, 3, false) + count(a, 0, 2, false) + count(a, 0, 1, false) + count(a, 0, 0, false);
    cout << ans1 - ans2 << endl;
  }
}

