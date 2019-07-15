#include <bits/stdc++.h>
//#define int long long
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
#define inf 1000000000 // 1e9
#define M   1000000007 // 1e9 + 7
using namespace std;
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
struct event{
	int x, v, t;
	pii id;
	event() {}
	event(int x, int v, int t, pii id) : x(x), v(v), t(t), id(id) {}
	bool operator<(const event & e) const{
		return x < e.x || (x == e.x && t < e.t) || (x == e.x && t == e.t && v < e.v);
	}
};

int dp[1515][1515];
pii back[1515][1515];
int32_t main(){
	fastio;
	int n;
	cin >> n;
	vector<event> events;
	vector<int> v(n);
	frr(i,n) cin >> v[i];
	for(int i=0;i<n;i++){
		int cur=0;
		for(int j=i;j<n;j++){
			cur+=v[j];
			events.pb(event(i,cur,0,pii(i,j)));
			events.pb(event(j,cur,1,pii(i,j)));
		}
	}
	sort(td(events));
	map<int, pair< int, pii > > m;
	for(auto e : events){
		if(e.t==0){
			int x = e.v;
			int l = e.id.ff;
			int r = e.id.ss;
			if(m.find(x)!=m.end()){
				dp[l][r] = m[x].ff+1;
				back[l][r] = m[x].ss;
			}
			else{
				dp[l][r] = 1;
				back[l][r] = pii(-1,-1);
			}
		}
		else{
			int x = e.v;
			int l = e.id.ff;
			int r = e.id.ss;
			if(!m.count(x) || dp[l][r]>m[x].ff){
				m[x].ff = dp[l][r];
				m[x].ss = pii(l,r);				
			}
		}
	}
	int cur = -1;
	pii x;
	for(int i=0;i<n;i++){
		for(int j=i; j<n; j++){
			if(dp[i][j] > cur){
				x.ff = i;
				x.ss = j;
				cur = dp[i][j];
			}
		}
	}
	vector< pii > ans;
	while(x.ff!=-1){
		ans.pb(x);
		x = back[x.ff][x.ss];
	}
	cout << ans.size() << endl;
	for(auto k : ans)
		cout << k.ff+1 << " " << k.ss+1 << endl;

}