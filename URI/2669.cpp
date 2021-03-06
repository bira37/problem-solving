#include <bits/stdc++.h>

//#define int long long
//#define double long double
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

/* Fast Fourier Transform Implementation */
/* Complex numbers implemented by hand */
/* Poly needs to have degree of next power of 2 (result poly has size next_pot2(2*n) */
/* Uses Roots of Unity (Z^n = 1, divide and conquer strategy)
/* Inverse FFT only changes to the conjugate of Primitive Root of Unity */
/* Remember to use round to get integer value of Coefficients of Poly C */
/* Iterative FFT is way faster (bit reversal idea + straightforward conquer for each block of each size) */
/* std::complex doubles the execution time */
/* FastConvolution receives a Poly A+Bi, and multiply A*B (imaginary part doesn't remains the same)*/

namespace FFT{

  struct Complex{
    double a, b;
  
    Complex(double a, double b) : a(a), b(b) {}
  
    Complex() : a(0), b(0) {}
  
    Complex conjugate() const {
      return Complex(a, -b);
    }
  
    double size2() const {
      return a*a + b*b;
    }
    
    void operator=(const Complex & b){
      this->a = b.a;
      this->b = b.b;
    }  
    Complex operator+(const Complex & y) const {
      return Complex(a + y.a, b + y.b);
    }
    Complex operator-(const Complex & y) const {
      return Complex(a - y.a, b - y.b);
    }
    Complex operator*(const Complex & y) const {
      return Complex(a*y.a - b*y.b, a*y.b + b*y.a);
    }
    Complex operator/(const double & x) const {
      return Complex(a/x, b/x);
    }
    Complex operator/(const Complex & y) const {
      return (*this)*(y.conjugate()/y.size2());
    }
  
  };

  struct Poly{
    vector<Complex> c;
    Poly() {}
  
    Poly(int n){
      int sz = (31 - __builtin_clz(n)%32) + 1;
      c.resize((1 << (sz-1) == n ? n : (1<<sz))<<1);
    }
  
    int size() const{
      return (int)c.size();
    }
    
  };

  inline Complex PrimitiveRootOfUnity(int n){
    const double PI = acos(-1);
    return Complex(cos(2*PI/(double)n), sin(2*PI/(double)n));
  }

  inline Complex InversePrimitiveRootOfUnity(int n){
    const double PI = acos(-1);
    return Complex(cos(-2*PI/(double)n), sin(-2*PI/(double)n));
  }

  void DFT(Poly & A, bool inverse){
    int n = A.size();
    int lg = 0;
    while(n > 0) lg++, n>>=1;
    n = A.size();
    lg-=2;

    for(int i=0; i<n; i++){
      int j = 0;
      for(int b=0; b <= lg; b++){
        if(i & (1 << b)) j |= (1 << (lg - b));
      }
      if(i < j) swap(A.c[i], A.c[j]);
    }

    for(int len=2; len <= n; len <<= 1){
      Complex w;
      if(inverse) w = InversePrimitiveRootOfUnity(len);
      else w = PrimitiveRootOfUnity(len);
    
      for(int i=0; i<n; i+=len){
        Complex x(1,0);
        for(int j=0; j<len/2; j++){
          Complex u = A.c[i+j], v = x*A.c[i+j+len/2];
           A.c[i+j] = u + v;
           A.c[i+j+len/2] = u - v;
           x = x*w;
        }
      }
    }
  
    if(inverse) for(int i=0; i<n; i++) A.c[i] = A.c[i]/n;
  }

  /* Skipable */
  Poly RecursiveFFT(Poly A, int n, Complex w){
    if(n == 1) return A;
  
    Poly A_even(n/2), A_odd(n/2);
  
    for(int i=0; i<n; i+=2){
      A_even.c[i/2] = A.c[i];
      A_odd.c[i/2] = A.c[i+1];
    }
  
    Poly F_even = RecursiveFFT(A_even, n/2, w*w);
    Poly F_odd = RecursiveFFT(A_odd, n/2, w*w);
    Poly F(n);
    Complex x(1, 0);
  
    for(int i=0; i<n/2; i++){
      F.c[i] = F_even.c[i] + x*F_odd.c[i];
      F.c[i + n/2] = F_even.c[i] -  x*F_odd.c[i];
      x = x*w;
    }
  
    return F;
  }
  /* Skipable */

  Poly Convolution(Poly & F_A, Poly & F_B){
    Poly F_C(F_A.size()>>1);
    for(int i=0; i<F_A.size(); i++) F_C.c[i] = F_A.c[i]*F_B.c[i];
    return F_C;
  }
  
  Poly FastMultiply(Poly & A){
    Poly C(A.size());
    
    DFT(A, false);
    
    for(int i=0; i<A.size(); i++) A.c[i] = A.c[i]*A.c[i];
    
    DFT(A, true);
    
    for(int i=0; i<A.size(); i++) C.c[i] = Complex(A.c[i].b/2, 0);
    
    return C;
  }
  
  Poly multiply(Poly & A, Poly & B){
    DFT(A, false);
  
    DFT(B, false);
    
    Poly C = Convolution(A, B);
    
    DFT(C, true);
  
    return C;
  }
  
};

int32_t main(){
  DESYNC;
  string s;
  cin >> s;
  int n = s.size();
  int p[n+1];
  p[0] = 0;
  for(int i=0; i<n; i++){
    p[i+1] = p[i] + (s[i] - 'a') + 1;
  }
  FFT::Poly A(p[n]+1);
  for(int i=0; i<=n; i++){
    A.c[p[i]].a = 1;
    A.c[p[n]-p[i]].b = 1;
  }
  FFT::Poly C = FFT::FastMultiply(A);
  int ans = 0;
  for(int i=p[n]+1; i<C.size(); i++){
    int val = (int)(C.c[i].a + 0.5);
    if(val > 0) ans++;
  }
  cout << ans << endl;    
}


