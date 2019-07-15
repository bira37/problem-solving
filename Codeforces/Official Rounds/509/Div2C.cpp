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
  int n,m,d;
  cin >> n >> m >> d;
  set< ii > s;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    s.insert(ii(x,i));
  }
  int ans[n];
  int cur_d = 1;
  int cur_min = 0;
  while(s.size() > 0){
    auto it = s.lower_bound(ii(cur_min, -1));
    if(it == s.end()){
      cur_min = 0;
      cur_d++;
    }
    else {
      ans[it->second] = cur_d;
      cur_min = it->first + d+1;
      s.erase(it);
    }
  }
  cout << cur_d << endl;
  for(int i=0; i<n; i++) cout << ans[i] << " ";
  cout << endl;
}

