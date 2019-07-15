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

/* Matrix Exponentiation Implementation */

struct Matrix{
  vector< vector<int> > m;
  Matrix() {}
  Matrix(int l, int c){
    m.resize(l, vector<int>(c));
  }
  
  Matrix operator *(Matrix b) const{
    Matrix c(m.size(), b.m[0].size());
    for(int i = 0; i<m.size(); i++){
      for(int j = 0; j<b.m[0].size(); j++){
        for(int k = 0; k<b.m.size(); k++){
          c.m[i][j] += mod(m[i][k]*b.m[k][j], M);
          c.m[i][j] = mod(c.m[i][j], M);
        }
      }
    }
    return c;
  }
   

  Matrix exp(int k){
    if(k == 1) return *this;
    Matrix c = (*this).exp(k/2);
    c = c*c;
    if(k%2) c = c*(*this);
    return c;
  }
}; 


int32_t main(){
  DESYNC;
  int n,m;
  cin >>n >> m;
  int dp[m+1];
  dp[0] = 1;
  for(int i=1; i<=m; i++){
    dp[i] = 0;
    if(i-m >= 0) dp[i] += dp[i-m];
    dp[i] += dp[i-1];
  }
  if(n <= m){
    cout << dp[n] << endl;
    return 0;
  }
  Matrix B(m+1, 1);
  for(int i=0; i<=m; i++) B.m[i][0] = dp[i];
  Matrix A(m+1, m+1);
  for(int i=0; i<m; i++){
    A.m[i][i+1] = 1;
  }
  A.m[m][1] = A.m[m][m] = 1;
  /*for(int i=0; i<=m; i++){
    for(int j=0; j<=m; j++){
      cout << A.m[i][j] << " ";
    }
    cout << endl;
  }
  for(int i=0; i<=m; i++){
    cout << B.m[i][0];
    cout << endl;
  }*/
  int ex = n-m;
  Matrix C = A.exp(ex)*B;
  cout << C.m[m][0] << endl;  
}

