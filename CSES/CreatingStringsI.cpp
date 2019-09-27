#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define pii pair<int,int>
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define td(v) v.begin(),v.end()
#define M   1000000007 // 1e9 + 7
#define MAXN 200100
using namespace std;
 
const int inf = 1e18;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int exp(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}
int n,k;
int a[MAXN];
int pre[MAXN];
 
int check(int x){
	int used=1;
	int atual=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x)return false;
		if(atual+a[i]>x){
			atual = a[i];
			used++;
		}else{
			atual+=a[i];
		}
	}
	if(used<=k)return true;
	return false;
}
 
int bs(){
	int l=1,r=1e18;
	int ans=1e18;
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid)){
			r = mid - 1;
			ans = min(ans,mid);
		}else l = mid+1;
		
	}
	
		
		return ans;
}
 
int32_t main(){
	fastio;
	string s;
	cin>>s;
	set<string> v;
	sort(s.begin(),s.end());
	do{
		v.insert(s);
	}while(next_permutation(s.begin(),s.end()));
	cout<<v.size()<<endl;
	for(set<string>::iterator it = v.begin();it!=v.end();it++){
		cout<<*it<<endl;
	}
}
