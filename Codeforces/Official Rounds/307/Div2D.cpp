#include <bits/stdc++.h>
 
#define int long long
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
 
using namespace std;
 
int n,k,l,mod;
 
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
			    c.m[i][j] %= mod;
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
 
int exp(int n, int k){
  if(k == 0) return 1;
  if(k == 1) return n;
  int aux = exp(n, k/2);
  aux %= mod;
  aux *= aux;
  aux %= mod;
  if(k%2) aux *= n;
  aux %= mod;
  return aux;
}
 
int get_inv(int val){
  return ((exp(2LL, n) - val)%mod + mod)%mod;
}
 
int32_t main(){
	DESYNC;
  cin >> n >> k >> l >> mod;
  if(l == 0 && k != 0){
    cout << 0 << endl;
    return 0;
  }
  if(l <= 62 && (1LL<<l) <= k){
    cout << 0 << endl;
    return 0;
  }
  int ans = 1;
  Matrix A(2,2);
  A.m[0][0] = 1;
  A.m[0][1] = 1;
  A.m[1][0] = 1;
  A.m[1][1] = 0;
  Matrix B(2, 1);
  B.m[0][0] = 2;
  B.m[1][0] = 1;
  Matrix C = A.exp(n-1) * B;
  int val = C.m[0][0];
  //cout << val << endl;
  val %= mod;
  for(int i=0; i<l; i++){
    if((1LL<<i) & k) ans *= get_inv(val);
    else ans *= val;
    ans %= mod;
  }
  ans %= mod;
  cout << ans << endl;     
}
 
