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

int dp[50][50][50];
int solve(int a ,int b, int c){
  if(dp[a][b][c] != -1) return dp[a][b][c];
  if(a == b or a == c or b == c){
    dp[a][b][c] = 1;
    cout << "dp[" << a << "][" << b << "][" << c << "] = " << dp[a][b][c] << endl;
    return 0;
  }
  if(a == 0 && b == 1){
    dp[a][b][c] = 0;
    cout << "dp[" << a << "][" << b << "][" << c << "] = " << dp[a][b][c] << endl;
    return 0;
  }
  if(a == 1 && b == 0){
    dp[a][b][c] = 0;
    cout << "dp[" << a << "][" << b << "][" << c << "] = " << dp[a][b][c] << endl;
    return 0;
  }
  if(a == 0 && c == 1){
    dp[a][b][c] = 0;
    cout << "dp[" << a << "][" << b << "][" << c << "] = " << dp[a][b][c] << endl;
    return 0;
  }
  if(a == 1 && c == 0){
    dp[a][b][c] = 0;
    cout << "dp[" << a << "][" << b << "][" << c << "] = " << dp[a][b][c] << endl;
    return 0;
  }
  if(b == 1 && c == 0){
    dp[a][b][c] = 0;
    cout << "dp[" << a << "][" << b << "][" << c << "] = " << dp[a][b][c] << endl;
    return 0;
  }
  if(b == 0 && c == 1){
    dp[a][b][c] = 0;
    cout << "dp[" << a << "][" << b << "][" << c << "] = " << dp[a][b][c] << endl;
    return 0;
  }
  int mx = 0;
  if(a-1 >= 0){
    int x = solve(a-1, b,c);
    if(x == 0) mx = 1;
  }
  if(b-1 >= 0){
    int x = solve(a, b-1,c);
    if(x == 0) mx = 1;
  }
  if(c-1 >= 0){
    int x = solve(a, b,c-1);
    if(x == 0) mx = 1;
  }
  dp[a][b][c] = mx;
  cout << "dp[" << a << "][" << b << "][" << c << "] = " << dp[a][b][c] << endl;
  return dp[a][b][c];
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int v[n];
  map<int,int> cnt;
  int cnt3 = 0, cnt2= 0;
  for(int i=0; i<n; i++){
    cin >> v[i];
    cnt[v[i]]++;
    if(cnt[v[i]] == 3) cnt3++;
    if(cnt[v[i]] == 2) cnt2++;
  }
  int lst = -1;
  sort(v, v+n);
  int plays = 0;
  if(cnt3 || cnt2 > 1){
    cout << "cslnb" << endl;
    return 0;
  }
  for(int i=0; i<n; i++){
    if(cnt[v[i]] >= 2 && cnt[v[i]-1] > 0){
      cout << "cslnb" << endl;
      return 0;
    }
  }
  if(cnt[0] >= 2){
    cout << "cslnb" << endl;
    return 0;
  }
  for(int i=0; i<n; i++){
    plays += (v[i] - i);
  }
  if(plays%2) cout << "sjfnb" <<endl;
  else cout << "cslnb" << endl;
}

