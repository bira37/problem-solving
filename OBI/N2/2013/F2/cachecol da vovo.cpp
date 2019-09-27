#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define td(v) v.begin(),v.end()
#define M   1000000007 // 1e9 + 7
#define MAXN 300100
using namespace std;
typedef pair<int,int> pii;
inline int mod(int n, int m){int ret = n%m; if(ret < 0) ret += m; return ret;}
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int exp(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }    else return mod(k*k,m);
}

struct matrix{
int mat[2][2];	
};
matrix I,base;

matrix mul(matrix a,matrix b){
	matrix c;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			c.mat[i][j] = 0;
			for(int k=0;k<2;k++){
				c.mat[i][j] = (c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%M;
			}
		}
	}
	return c;
}
matrix expo(int n){
	if(n==1)return base;
	if(n==0)return I;
	if(n&1)return mul(base,expo(n-1));
	matrix k = expo(n/2);
	return mul(k,k);
}

int32_t main(){
	fastio;
	int n;
	cin>>n;
	base.mat[0][0]=3;
	base.mat[1][1]=base.mat[0][1]=2;
	base.mat[1][0]=2;
	I.mat[0][0]=I.mat[1][1]=1;
	I.mat[0][1]=I.mat[1][0]=0;
	base = expo(n-1);
	int r = 0;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			r+=base.mat[i][j];
			r=r%M;
		}
	}
	if(r<0)r+=M;
	cout<<(r*6)%M<<endl;
}