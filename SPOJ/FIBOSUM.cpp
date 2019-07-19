#include <bits/stdc++.h>
#define int long long
#define MOD (int)1e9 + 7

using namespace std;

typedef vector< vector<int> > Matrix;

int t,n,m;

Matrix multimatrix(const Matrix & a, const Matrix & b){
	Matrix c(a.size(), vector<int>(b[0].size()));
	for(int i = 0; i<a.size(); i++){
		for(int j = 0; j<b[0].size(); j++){
			for(int k = 0; k<b.size(); k++){
				c[i][j] += (a[i][k]*b[k][j])%(MOD);
				c[i][j] %= (MOD);
			}
		}
	}
	return c;
}

Matrix expo(Matrix & a, int k){
	if(k == 1) return a;
	Matrix c = expo(a, k/2);
	c = multimatrix(c, c);
	if(k%2) c = multimatrix(c, a);
	return c;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> m;
		Matrix a(3, vector<int>(1));
		a[0][0] = 1;
		a[1][0] = 0;
		a[2][0] = 1;
	
		Matrix t(3, vector<int>(3));
		t[0] = {1, 1, 0};
		t[1] = {1, 0, 0};
		t[2] = {1, 1, 1};
		
		if(n <= 1){
			if(m == 0) cout << 0 << endl;
			else if(m == 1) cout << 1 << endl;
			else {
				Matrix ans = expo(t, m-1);
				ans = multimatrix(ans, a);
				cout << ans[2][0] << endl;
			}
		}
		else if(n == 2){
			Matrix ans2 = expo(t, m-1);
			ans2 = multimatrix(ans2, a);
			cout << ans2[2][0] - 1 << endl;
		}
		else {
			Matrix ans  = expo(t, n-2);
			Matrix ans2 = expo(t, m-1);
			ans = multimatrix(ans, a);
			ans2 = multimatrix(ans2, a);
			int imprime = (ans2[2][0] - ans[2][0]);
			if(imprime < 0) imprime+=MOD;
			cout << imprime << endl;
		}
	}
} 
			
		






