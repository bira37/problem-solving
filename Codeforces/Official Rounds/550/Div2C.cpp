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
  cin >> n;
  vector<int> v(n);
  vector<int> ans1, ans2;
  for(int i=0; i<n; i++) cin>> v[i];
  sort(v.begin(), v.end());
  ans1.pb(v[0]);
  for(int i=1; i<v.size(); i++){
      if(ans1.back() != v[i]) ans1.pb(v[i]);
      else if(ans2.size() == 0 || ans2.back() != v[i]) ans2.pb(v[i]);
      else {
          cout << "NO" << endl;
          return 0;
      }
  }
  cout << "YES" << endl;
  reverse(ans2.begin(), ans2.end());
  cout << ans1.size() << endl;
  for(int x : ans1) cout << x << " ";
  cout << endl;
  cout << ans2.size() << endl;
  for(int x : ans2) cout << x << " ";
  cout << endl;
}