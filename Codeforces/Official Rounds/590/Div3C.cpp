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
  int q;
  cin >> q;
loop:  while(q--){
    int n;
    cin >> n;
    char mat[2][n];
    for(int i=0; i<2; i++){
      for(int j=0; j<n; j++) cin >> mat[i][j];
    }
    int x = 0, y = 0; bool same = true;
    while(true){
      if(x == 0 and y == n) break;
      //cout << "at " << x << " " << y << endl;
      if(x == 1 and y == n){
        cout << "YES" << endl;
        goto loop;
      }
      if(same){
        if(mat[x][y] >= '1' and mat[x][y] <= '2'){
          y++;
          same = true;
        }
        else {
          if(x == 1) x=0;
          else x = 1;
          same = false;
        }
      }
      else {
        if(mat[x][y] >= '3' and mat[x][y] <= '6'){
          y++;
          same = true;
        }
        else break;
      }
    }
    cout << "NO" << endl;
  }
}
