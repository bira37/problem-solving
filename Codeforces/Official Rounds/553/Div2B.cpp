#include <bits/stdc++.h>

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
  int n,m; cin >> n >> m;
  int a[n][m];
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> a[i][j];
    }
  }
  
  for(int b = 0; b <= 10; b++){
    int sum = 0;
    for(int i=0; i<n; i++){
      sum ^= ((1<<b) & a[i][0]);
    }
    if(sum > 0){
      cout << "TAK" << endl;
      for(int i=0; i<n; i++) cout << 1 << " "; 
      cout << endl;
      return 0;
    }
    for(int i=0; i<n; i++){
      sum ^= ((1<<b) & a[i][0]);
      for(int j=1; j<m; j++){
        sum ^= ((1<<b) & a[i][j]);
        if(sum > 0){
          cout << "TAK" << endl;
          for(int k=0; k<n; k++){
            if(k == i) cout << j+1 << " ";
            else cout << 1 << " "; 
          }
          cout << endl;
          return 0;
        }
        sum ^= ((1<<b) & a[i][j]);
      }
      sum ^= ((1<<b) & a[i][0]);
    }
  }
  cout << "NIE" << endl;
}

