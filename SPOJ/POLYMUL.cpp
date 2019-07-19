#include <bits/stdc++.h>
#define double long double
using namespace std;

/* Fast Fourier Transform Implementation */
/* Complex numbers implemented by hand */
/* Poly needs to have degree of next power of 2 (result poly has size next_pot2(2*n) */
/* Uses Roots of Unity Idea (Z^n = 1, divide and conquer strategy)
/* Inverse FFT only changes to the conjugate of Primitive Root of Unity */

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
	
	Poly(int sz){
		c.resize(sz);
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

inline Poly FFT(Poly A, int n, Complex w){
	if(n == 1) return A;
	
	Poly A_even(n/2), A_odd(n/2);
	
	for(int i=0; i<n; i+=2){
		A_even.c[i/2] = A.c[i];
		A_odd.c[i/2] = A.c[i+1];
	}
	
	Poly F_even = FFT(A_even, n/2, w*w);
	Poly F_odd = FFT(A_odd, n/2, w*w);
	Poly F(n);
	Complex x(1, 0);
	
	for(int i=0; i<n/2; i++){
		F.c[i] = F_even.c[i] + x*F_odd.c[i];
		F.c[i + n/2] = F_even.c[i] -  x*F_odd.c[i];
		x = x*w;
	}
	
	return F;
}

Poly Convolution(const Poly & F_A, const Poly & F_B){
	Poly F_C((int)F_A.size());
	for(int i=0; i<(int)F_A.size(); i++) F_C.c[i] = F_A.c[i]*F_B.c[i];
	return F_C;
}

Poly operator*(const Poly & A, const Poly & B){
	Complex w = PrimitiveRootOfUnity((int)A.size());
	Poly F_A = FFT(A, (int)A.size(), w);
	Poly F_B = FFT(B, (int)B.size(), w);
	
	Poly F_C = Convolution(F_A, F_B);
	
	Complex w_ = InversePrimitiveRootOfUnity((int)A.size());
	
	Poly C = FFT(F_C, (int)F_C.size(), w_);
	
	for(int i=0; i<(int)C.size(); i++) C.c[i] = C.c[i]/(double)C.size();
	
	return C;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	//srand(time(NULL));
	while(t--){
		
		int n;
		cin >> n;
		n++;
		int sz = 1;
		while(sz < 2*n) sz <<= 1;
		Poly A(sz), B(sz);
		//vector<long long> a(sz), b(sz);
		
		//cout << "Multiply A(x) : ";
		for(int i=n-1; i>=0; i--){
			int x;
			cin >> x;
			//cout << x << " ";
			//a[i] = x;
			A.c[i] = Complex(x,0);
		}
		//cout << endl;
		//cout << "With B(x) : ";
		for(int i=n-1; i>=0; i--){
			int x;
			cin >> x;
			//cout << x << " ";
			//b[i] = x;
			B.c[i] = Complex(x,0);
		}
		//cout << endl;
		Poly C = A*B;
		
		/*vector<long long> c(sz);
		for(int i=0; i<sz; i++){
			if(a[i] == 0) continue;
			for(int j=0; j < sz; j++){
				if(b[j] == 0) continue;
				c[i+j] += a[i]*b[j];
			}
		}*/
		
		/*cout << "Result from brute : ";
		for(int i=0; i<sz; i++) cout << c[i] << " ";
		cout << endl;
		cout << "Result from FFT : ";
		for(int i=0; i<sz; i++) cout << (long long)round(C.c[i].a) << " ";
		cout << endl;
		int miss = 0;
		for(int i=0; i<sz; i++) miss += ((long long)round(C.c[i].a) != c[i]);
		if(miss) cout << "Wrong" << endl;
		else cout << "OK" << endl; */
		
		vector<long long> ans;
		n--;
		for(int i=2*n; i>=0; i--) ans.push_back((long long)round(C.c[i].a));
		for(int i=0; i<ans.size(); i++){
			if(i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
		
	}
}
	
	 
