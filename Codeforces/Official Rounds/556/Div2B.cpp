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
      
char a[55][55];

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int filled = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> a[i][j];
    }
  }
  for(int i=1; i<n-1; i++){
    for(int j=1; j<n-1; j++){
      if(a[i][j] == '.' && a[i-1][j] == '.' && a[i+1][j] == '.' && a[i][j-1] == '.' && a[i][j+1] == '.'){
        a[i][j] = a[i+1][j] = a[i-1][j] = a[i][j+1] = a[i][j-1] = '#';
      }
    }
  }
  filled = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      filled += (a[i][j] == '#');
    }
  }
  cout << (filled == n*n ? "YES" : "NO") << endl;
}

