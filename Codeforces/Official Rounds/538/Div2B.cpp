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
  int n,m,k;
  cin >> n >> m >> k;
  int v[n];
  vector<bool> mk(n, false);
  vector< ii > s;
  for(int i=0; i<n; i++){
    cin >> v[i]; 
    s.pb(ii(v[i], i));
  }
  sort(s.begin(), s.end(), greater< ii > ());
  for(int i=0; i<m*k; i++){
    mk[s[i].ss] = true;
  }
  vector<int> ans;
  int val = 0;
  int cur = 0;
  int active = 0;
  for(int i=0; i<n; i++){
    active += mk[i];
    val += mk[i]*v[i];
    if(active == m){
      ans.pb(i);
      active = 0;
    }
  }
  cout << val << endl;
  ans.pop_back();
  for(int x : ans) cout << x+1 << " ";
  cout << endl;
}

