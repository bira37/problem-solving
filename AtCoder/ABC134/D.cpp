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

int cnt[212345];

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  set<int> ans;
  int v[n];
  for(int i=1; i<=n; i++){
    cin >> v[i];
  }
  for(int i=n; i>=1; i--){
    int cur = 0;
    for(int j=i; j<=n; j+=i){
      cur += cnt[j];
    }
    if(cur%2 != v[i]){
      ans.insert(i);
      cnt[i]++;
    }
  }
  cout << ans.size() << endl;
  if(ans.size() > 0) for(int x : ans) cout << x << " ";
  if(ans.size() > 0) cout << endl;     
}


