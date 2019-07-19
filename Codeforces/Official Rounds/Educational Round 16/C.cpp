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
  vector<int> odd, even;
  for(int i=1; i<=n*n; i++){
    if(i%2) odd.pb(i);
    else even.pb(i);
  }
  int mat[n][n];
  memset(mat, -1, sizeof mat);
  mat[n/2][n/2] = odd.back();
  odd.pop_back();
  for(int i=0; i<n; i++){
    if(mat[i][i] != -1) continue;
    mat[i][i] = even.back();
    even.pop_back();
  }
  for(int i=0; i<n; i++){
    if(mat[i][n-1-i] != -1) continue;
    mat[i][n-1-i] = even.back();
    even.pop_back();
  }
  for(int i=0; i<n; i++){
    if(mat[i][n/2] != -1) continue;
    mat[i][n/2] = odd.back();
    odd.pop_back();
  }
  for(int i=0; i<n; i++){
    if(mat[n/2][i] != -1) continue;
    mat[n/2][i] = odd.back();
    odd.pop_back();
  }
  for(int i=0; i<n; i++){
    if(mat[0][i] != -1) continue;
    mat[0][i] = odd.back();
    odd.pop_back();
  }
  for(int i=0; i<n; i++){
    if(mat[n-1][i] != -1) continue;
    mat[n-1][i] = odd.back();
    odd.pop_back();
  }
  for(int i=0; i<n/2; i++){
    for(int j=0; j<n/2; j++){
      if(j < i) continue;
      if(mat[i][j] != -1) continue;
      mat[i][j] = odd.back();
      odd.pop_back();
    }
  }
  for(int i=0; i<n/2; i++){
    for(int j=n/2; j<n; j++){
      if(j > n-1-i) continue;
      if(mat[i][j] != -1) continue;
      mat[i][j] = odd.back();
      odd.pop_back();
    }
  }
  for(int i=n/2; i<n; i++){
    for(int j=n/2; j>0; j--){
      if(j < n-1-i) continue;
      if(mat[i][j] != -1) continue;
      mat[i][j] = odd.back();
      odd.pop_back();
    }
  }
  for(int i=n/2; i<n; i++){
    for(int j=n/2; j<n; j++){
      if(j > i) continue;
      if(mat[i][j] != -1) continue;
      mat[i][j] = odd.back();
      odd.pop_back();
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(mat[i][j] != -1) continue;
      mat[i][j] = even.back();
      even.pop_back();
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}
 
