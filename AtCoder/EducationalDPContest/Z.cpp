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
#define inf 1000000000 // 1e9
#define MAXN 1000010
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

struct point{
	int x,y;
	point(){}
	point (int _x,int _y){
		x = _x;
		y = _y;
	}
	point operator+(const point & oth){
		return point(x+oth.x,y+oth.y);
	}
	point operator-(const point &oth){
		return point(x-oth.x,y-oth.y);
	}
};

int dot(point a,point b){
	return a.x*b.x + a.y*b.y;
}
int cross(point a,point b){
	return a.x*b.y - a.y*b.x;
}
int ccw(point a,point b,point c){
	int dir = cross(b-a,c-b);
	return dir<0;//convexo
}
int n,c;
int h[MAXN];
int dp[MAXN];
point line[4*MAXN];
vector<int> M;
vector<int> B;

int f(point a,int x){
	point c(x,1);
	return dot(a,c);
}

void add_line(point nw,int v=1,int l=0,int r = MAXN){
	int m = (l+r)/2;
	bool lef = f(nw,l) < f(line[v],l);
	bool mid = f(nw,m) < f(line[v],m);
	if(mid){
		swap(line[v],nw);
	}
	if(r-l==1){
		return;
	}else if(lef!=mid){
		add_line(nw,2*v,l,m);
	}else{
		add_line(nw,2*v+1,m,r);
	}
}

int get(int x,int v=1,int l=0,int r = MAXN){
	int m = (l+r)/2;
	if(r-l==1){
		return f(line[v],x);
	}else if(x<m){
		return min(f(line[v],x),get(x,2*v,l,m));
	}else{
		return min(f(line[v],x),get(x,2*v + 1 ,m ,r));
	}
}


int32_t main(){
	fastio;
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	dp[1]=0;
	point a1 (-2*h[1],dp[1]+h[1]*h[1]);
	add_line(a1,1,0,MAXN);
	for(int i=2;i<=n;i++){
		dp[i] = h[i]*h[i]+c;
		dp[i] = min(dp[i],(h[i]*h[i]+c)+get(h[i],1,0,MAXN));
		point nw(-2*h[i],dp[i]+h[i]*h[i]);
		add_line(nw,1,0,MAXN);
	}
	cout<<dp[n]<<endl;
}
