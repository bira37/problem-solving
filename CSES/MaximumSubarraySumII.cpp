#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define td(v) v.begin(),v.end()
#define inf 1000000000 // 1e9
#define M   998244353 // 1e9 + 7
#define MAXN 200100
using namespace std;
typedef pair<int,int> pii;
inline int mod(int n, int m){if(n%m==0)return m;
int ret = n%m; if(ret < 0) ret += m; return ret; }
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

int pre[MAXN];
const int INF = 1e18;
int32_t main(){
    fastio;
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
	set<pii> S;
	set<pii> S2;
	multiset<int> S3;
	int ans = -INF;
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i] = pre[i-1]+v[i];
	}
	for(int i=a;i<=n;i++){
		S2.insert(pii(i-a,pre[i-a]));
		S3.insert(pre[i-a]);
		while(i-S2.begin()->first>b){
			S3.erase(S3.find(S2.begin()->second));
			S2.erase(S2.begin());		 			
		}
		ans = max(ans, pre[i] - *S3.begin());
	}
	/*
	int i = n-1;
	while(S.size() && i-S.begin()->first>=a){
			S2.insert(pii(S.begin()->first,S.begin()->second));
			S3.insert(S.begin()->second);
			S.erase(S.begin());
		
		}
	while(S2.size() &&  i-S2.begin()->first>b){
			S3.erase(S3.find(S2.begin()->second));
			S2.erase(S2.begin());
	}
	while(S2.size() && i-S2.begin()->first>=a && i-S2.begin()->first<=b){
		ans = max(ans,atual - *S3.begin());
		S3.erase(S3.find(S2.begin()->second));
			S2.erase(S2.begin());
	}
	*/
	cout<<ans<<endl;
}