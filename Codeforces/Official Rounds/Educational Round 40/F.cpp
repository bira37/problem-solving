#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define endl '\n'
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second
#define int long long

using namespace std;

inline int mod(int & n){ return n%1000000007; } 

/* Matrix Exponentiation Implementation */

typedef vector< vector<int> > Matrix;

Matrix operator *(const Matrix & a, const Matrix & b){
	Matrix c(a.size(), vector<int>(b[0].size()));
	for(int i = 0; i<a.size(); i++){
		for(int j = 0; j<b[0].size(); j++){
			for(int k = 0; k<b.size(); k++){
				c[i][j] += (a[i][k]*b[k][j]);
				c[i][j] = mod(c[i][j]);
			}
		}
	}
	return c;
}

Matrix exp(Matrix & a, int k){
	if(k == 1) return a;
	Matrix c = exp(a, k/2);
	c = c*c;
	if(k%2) c = c*a;
	return c;
}

struct Event{
	int x, l;
	bool t;
	Event() {}
	Event(int x, int l, bool t) : x(x), l(l), t(t) {}
};

bool cmp(const Event & a, const Event & b){
	return a.x < b.x || (a.x == b.x && a.t < b.t);
}

int32_t main(){
	int n, m;
	cin >> n >> m;
	vector<Event> e;
	for(int i=0; i<n; i++){
		int x,l,r;
		cin >> x >> l >> r;
		x--;
		e.push_back(Event(l, x, 1));
		e.pb(Event(r+1, x, 0));
	}
	e.pb(Event(m+1, -1, 0));
	sort(e.begin(), e.end(), cmp);
	
	Matrix A(3, vector<int>(3));
	Matrix B(3, vector<int>(3));
	
	A[0][0] = 1;
	A[0][1] = 1;
	A[0][2] = 0;
	A[1][0] = A[1][1] = A[1][2] = 1;
	A[2][0] = 0;
	A[2][1] = 1;
	A[2][2] = 1;
	B[0][0] = 1;
	B[0][1] = 0;
	B[0][2] = 0;
	B[1][0] = 0;
	B[1][1] = 1;
	B[1][2] = 0;
	B[2][0] = 0;
	B[2][1] = 0;
	B[2][2] = 1;
	
	int op[] = {0,0,0};
	
	int curr = 2;
	for(int i=0; i<e.size(); i++){
		int times = e[i].x - curr;
		curr = e[i].x;
		//cout << "at " << curr << " " << times << endl;
		if(times > 0) {
			Matrix N = exp(A, times);
			B = N*B;
		}
		//cout << "    " << A[0][0] << "    " << A[0][1] << "    " << A[0][2] << endl;
		//cout << "    " << A[1][0] << "    " << A[1][2] << "    " << A[1][2] << endl;
		//cout << "    " << A[2][0] << "    " << A[2][1] << "    " << A[2][2] << endl;
		//cout << endl;
		//cout << "    " << B[0][0] << "    " << B[0][1] << "    " << B[0][2] << endl;
		//cout << "    " << B[1][0] << "    " << B[1][1] << "    " << B[1][2] << endl;
		//cout << "    " << B[2][0] << "    " << B[2][1] << "    " << B[2][2] << endl;
		if(e[i].l == 0){
			if(e[i].t == 1){
				op[0]++;
				A[0][0] = A[0][1] = A[0][2] = 0;
			}
			else {
				op[0]--;
				if(op[0] > 0) continue;
				A[0][0] = 1;
				A[0][1] = 1;
				A[0][2] = 0;
			}
		}
		else if(e[i].l == 1){
			if(e[i].t == 1){
				op[1]++;
				A[1][0] = A[1][1] = A[1][2] = 0;
			}
			else{
				op[1]--;
				if(op[1] > 0) continue;
				A[1][0] = A[1][1] = A[1][2] = 1;
			}
		}
		else if(e[i].l == 2){
			if(e[i].t == 1){
				op[2]++;
				A[2][0] = A[2][1] = A[2][2] = 0;
			}
			else {
				op[2]--;
				if(op[2] > 0) continue;
				A[2][0] = 0;
				A[2][1] = 1;
				A[2][2] = 1;
			}
		}
	}
	cout << B[1][1] << endl;
}