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
  int n,m,h;
  cin >> n >> m >> h;
  int col[m];
  int row[n];
  int top[n][m];
  for(int i=0; i<m; i++) cin >> col[i];
  for(int i=0; i<n; i++) cin >> row[i];
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++) cin >> top[i][j];
  }
  int ans[n][m];
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int cell = row[i];
      cell = min(row[i], col[j]);
      if(top[i][j] == 0) cell = 0;
      ans[i][j] = cell;
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(j > 0) cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }
      
}

