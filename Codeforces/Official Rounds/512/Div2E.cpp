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

int convert(int x){
  string s;
  int ans = 0;
  for(int i=0; i<61; i++){
    if((1LL<<i) & x) ans++;
  }
  return ans;
}

int v[312345];

int32_t main(){
  //DESYNC;
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    v[i] = convert(x);
  }
  int ans = 0;
  for(int i=0; i<n; i++){
    int cur = 0;
    int mx = 0;
    for(int j = i; j<i+130 && j < n; j++){
      cur += v[j];
      mx = max(mx, v[j]);
      if(cur%2 == 0 && 2*mx > cur){
        ans--;
      }
    }
  }
  int p[2][n+1];
  int cur = 0;
  p[1][0] = 0;
  p[0][0] = 1;
  for(int i=1; i<=n; i++){
    //cout << "v[" << i << "] = " << v[i-1] << endl;
    cur += v[i-1];
    if(cur%2){
      ans += p[1][i-1];
      p[1][i] = p[1][i-1] + 1;
      p[0][i] = p[0][i-1];
    }
    else{
      ans += p[0][i-1];
      p[0][i] = p[0][i-1] + 1;
      p[1][i] = p[1][i-1];
    }
    //cout << "cur = " << cur << endl;
    //cout << "p[0][" << i << "] = " << p[0][i] << endl;
    //cout << "p[1][" << i << "] = " << p[1][i] << endl;
    //cout << "ans = " << ans << endl;
  }
  cout <<ans << endl;
}

