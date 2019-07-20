#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_tuple
#define mt make_tuple
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
/* Matrix Exponentiation Implementation */
 
int p, ax,bx,cx,kx,nx, ay, by,cy,ky,ny, x;
 
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
          c.m[i][j] += (m[i][k]*b.m[k][j]);
          c.m[i][j] = mod(c.m[i][j], p);
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
  int t;
  cin >> t;
  while(t--){
    cin >> p >> ax >> bx >> cx >> kx >> nx;
    cin >> ay >> by >> cy >> ky >> ny;
    cin >> x;
    Matrix M(4,4);
    M.m[0][0] = 0; M.m[0][1] = 1; M.m[0][2] = 1; M.m[0][3] = 0;
    M.m[1][0] = kx; M.m[1][1] = 0; M.m[1][2] = 0; M.m[1][3] = 1;
    M.m[2][0] = 1; M.m[2][1] = kx; M.m[2][2] = 0; M.m[2][3] = 0;
    M.m[3][0] = 0; M.m[3][1] = 0; M.m[3][2] = 1; M.m[3][3] = 0;
    if(nx-1 >= 1) M = M.exp(nx-1);
    else {
      M.m[0][0] = 1; M.m[0][1] = 0; M.m[0][2] = 0; M.m[0][3] = 0;
      M.m[1][0] = 0; M.m[1][1] = 1; M.m[1][2] = 0; M.m[1][3] = 0;
      M.m[2][0] = 0; M.m[2][1] = 0; M.m[2][2] = 1; M.m[2][3] = 0;
      M.m[3][0] = 0; M.m[3][1] = 0; M.m[3][2] = 0; M.m[3][3] = 1;
    }
    set<int> s;
    for(int h=0; h<p; h++){
      Matrix B(4, 1);
      B.m[0][0] = ax;
      B.m[1][0] = bx;
      B.m[2][0] = cx;
      B.m[3][0] = h;
      int got = (M*B).m[0][0];
      if(got == x) s.insert(h);
    }
    set<int> ans;
    M.m[0][0] = 0; M.m[0][1] = 1; M.m[0][2] = 1; M.m[0][3] = 0;
    M.m[1][0] = ky; M.m[1][1] = 0; M.m[1][2] = 0; M.m[1][3] = 1;
    M.m[2][0] = 1; M.m[2][1] = ky; M.m[2][2] = 0; M.m[2][3] = 0;
    M.m[3][0] = 0; M.m[3][1] = 0; M.m[3][2] = 1; M.m[3][3] = 0;
    if(ny-1 >= 1) M = M.exp(ny-1);
    else {
      M.m[0][0] = 1; M.m[0][1] = 0; M.m[0][2] = 0; M.m[0][3] = 0;
      M.m[1][0] = 0; M.m[1][1] = 1; M.m[1][2] = 0; M.m[1][3] = 0;
      M.m[2][0] = 0; M.m[2][1] = 0; M.m[2][2] = 1; M.m[2][3] = 0;
      M.m[3][0] = 0; M.m[3][1] = 0; M.m[3][2] = 0; M.m[3][3] = 1;
    }
    for(int h : s){
      Matrix B(4, 1);
      B.m[0][0] = ay;
      B.m[1][0] = by;
      B.m[2][0] = cy;
      B.m[3][0] = h;
      int got = (M*B).m[0][0];
      ans.insert(got);
    }
    if(ans.size() == 1) cout << *ans.begin() << endl;
    else cout << "UNKNOWN" << endl;
  } 
}
 
