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
#define MAXN 100100
using namespace std;
typedef pair<int,int> pii;
const int inf = 1e9;
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
int32_t main(){
	fastio;
	int n,l,r;
	cin>>n>>l>>r;
	vector<int> v;
//	v.pb(l);
//	v.pb(r);
	for(int i=0;i<n;i++){
		int x;cin>>x;v.pb(x);
	}
	sort(v.begin(),v.end());
    int best = -1;
	
	if(v[0]>l){
		best = max(best,v[0]-l);
	}
	
	for(int i=0;i<n-1;i++){
		//cai entre i e i+1;
		int mid = (v[i] + v[i+1])/2;
		if(mid<l || mid>r)continue;
		int atual = min(mid-v[i],v[i+1]-mid);
		best = max(atual,best);
	}
	if(v[n-1]<r){
		best = max(best,r-v[n-1]);
	}
	cout<<best<<endl;
	 
}