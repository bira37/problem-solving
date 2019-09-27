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

struct Edge{
	int a,b,cost;
};

int d[2550];
int d2[2550];
const int inf = 1e15;

int32_t main(){
	fastio;
	int n,m;
	cin>>n>>m;
	vector<Edge> v(m);
	for(int i=0;i<m;i++){
		cin>>v[i].a>>v[i].b>>v[i].cost;
		v[i].cost=-v[i].cost;
	}
	for(int i=1;i<=n;i++){
		d[i] = inf;
	}
	d[1]=0;
	for(int i=0;i<n-1;i++){
		int x = -1;
		
		for(int j=0;j<m;j++){
			
		  //	cout<<d[v[j].a]<<" "<<v[j].a<<" "<<v[j].b<<" "<<v[j].cost<<endl;
		  if(d[v[j].a]!=inf){
			  if(d[v[j].b]>d[v[j].a]+v[j].cost){
				  d[v[j].b] = d[v[j].a]+v[j].cost;
				  x = v[j].b;
			  }
		  }
		}
		
		if(x==-1)break;
		
	}
	
	for(int i=1;i<=n;i++)d2[i] = d[i];
	for(int i=0;i<1;i++){
		int x = -1;
		
		for(int j=0;j<m;j++){
		  if(d2[v[j].a]!=inf){
			  if(d2[v[j].b]>d2[v[j].a]+v[j].cost){
				  d2[v[j].b] = d2[v[j].a]+v[j].cost;
				  x = v[j].b;

			  }
		  }
		}
		
		
		if(x==-1){
			break;
		}
	}
	int flag = false;
	
	for(int j=0;j<m;j++){
		if(v[j].b==1 || v[j].b==n){
			if(d2[v[j].a]<d[v[j].a])flag = true;
		}
		if(v[j].a==1 || v[j].a==n){
			if(d2[v[j].a]<d[v[j].a])flag = true;
		}
	}
	
	if(flag){
		cout<<-1<<endl;
	}else cout<<-d[n]<<endl;
	
}