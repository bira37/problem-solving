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

bool vis[5123][5123] = {0};
bool used[5123] = {0};
int32_t main(){
  DESYNC;
  int n,k;
  cin >> n >> k;
  int v[n];
  int ans[n];
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  int prior = 1;
  for(int i=0; i<n; i++){
    int use = -1;
    while(used[prior] && prior <= k) prior++;
    for(int j=1; j<=k; j++){
      if(vis[v[i]][j]) continue;
      use = j;
      break;
    }
    if(use == -1){
      cout << "NO" <<endl;
      return 0;
    }
    if(!vis[v[i]][prior] && prior <= k){
      use = prior;
      prior++;
    }
    used[use] = true;
    vis[v[i]][use] = true;
    ans[i] = use;
  }
  if(prior < k){
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" <<endl;
  for(int i=0; i<n; i++) cout << ans[i] << " ";
  cout << endl;
}

