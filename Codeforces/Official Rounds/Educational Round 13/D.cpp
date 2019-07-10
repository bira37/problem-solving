#include <bits/stdc++.h>
#define int long long
#define MOD (int)1e9 + 7
 
using namespace std;
 
typedef vector< vector<int> > Matrix;
 
int a,b,n,x;
 
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
	cin >> a >> b >> n >> x;
	Matrix base(2, vector<int>(1));
	base[0][0] = x;
	base[1][0] = 1;
 
	Matrix t(2, vector<int>(2));
	t[0] = {a, b};
	t[1] = {0, 1};
	
	Matrix ans = expo(t, n);
	ans = multimatrix(ans, base);
	cout << ans[0][0] << endl;
} 
