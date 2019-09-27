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
#define MAXN 600100
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

int n,q;
int pessoas;
int bit[2*MAXN];
int t[8*MAXN];

void up_t(int no,int i,int j,int pos,int val){
	if(i==j){
	
		t[no] = max(val,t[no]);
	}else{
		int m =(i+j)/2;
		if(pos<=m)up_t(2*no,i,m,pos,val);
		else up_t(2*no+1,m+1,j,pos,val);
		t[no] = max(max(t[no*2],t[no*2+1]),t[no]);
	}

}

int query(int no,int i,int j,int p,int k){
	if(i>p)return 0;
	if(t[no]<=k)return 0;
	if(i==j)return i;
		int m = (i+j)/2;
	if(j>p)return max(query(2*no,i,m,p,k),query(2*no+1,m+1,j,p,k));
	if(t[no*2+1]>k)return query(2*no+1,m+1,j,p,k);
	return query(2*no,i,m,p,k);
	
}

void update(int x,int val){
	while(x<=n+q){
	bit[x]+=val;
	x+=(x&-x);
	}
}

int sum(int x){
	int r=0;
	while(x>0){
		r+=bit[x];
		x-=(x&-x);
	}
	return r;
}

int busca(int k){
	int pos = 0;
	for(int i=30;i>=0;i--){
		int pot = (1LL<<i);
		if(pos+pot>n+q)continue;
		if(bit[pos+pot]<=k){
			k-=bit[pos+pot];
			pos+=pot;
		}
	}
	return pos;
}

int pos[2*MAXN];

struct Q{
int op,a,b;	
};
int H[MAXN*2];
int32_t main(){
//	fastio;
	cin>>n;
	vector<Q> v;
	for(int i=0;i<n;i++){
		int h;
		cin>>h;
		Q aux = {0,i,h};
		v.pb(aux);
	}
	cin>>q;
	for(int i=n;i<n+q;i++){
		int op,a,b;
		cin>>op>>a>>b;
		Q aux = {op,a,b};
		v.pb(aux);
	}
	for(int i=1;i<=n+q;i++)update(i,1);//preenche a bit
	
	for(int i=n+q-1;i>=0;i--){
		if(v[i].op==0){
			pos[i] = busca(v[i].a)+1;
			update(pos[i],-1);
		}else pos[i] = busca(v[i].a - 1) + 1;
	//	cout<<i<<" "<<pos[i]<<endl;
	}
	memset(t,0,sizeof(t));
	for(int i=0;i<n+q;i++){
		if(v[i].op==0){
			H[pos[i]]=v[i].b;
			up_t(1,1,n+q,pos[i],H[pos[i]]);
			update(pos[i],1);
		}else{
   	      cout<<sum(query(1,1,n+q,pos[i],H[pos[i]]+v[i].b))<<endl;
		}
	}

}