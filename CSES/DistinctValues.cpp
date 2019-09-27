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
typedef vector<int> vi;
typedef set<int> se;
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
const int N = 200100;
int arvore[4*N];
int A[N];

struct Query{
	   int l,r;
	   int id;
	  	
};
int cmp(Query a,Query b){
	return a.r<b.r;
}


void build(int no,int i,int j){
	int l = 2*no,r=2*no+1,m=(i+j)>>1;
	if(i==j){
		arvore[no]=A[i];
	}else{
		build(l,i,m);
		build(r,m+1,j);
		arvore[no]=arvore[l]+arvore[r];
	}
}

void att(int no,int i,int j,int pos,int val){
	int l = 2*no,r=2*no+1,m=(i+j)>>1;
	if(i==j){
		arvore[no]+=val;
	}else{
		if(pos<=m){
			att(l,i,m,pos,val);
		}else{
			att(r,m+1,j,pos,val);
		}
		arvore[no]=arvore[l]+arvore[r];		
	}
}
int query(int no,int i,int j,int a,int b){
	int l = 2*no,r=2*no+1,m=(i+j)>>1;
	if(i>b || j<a || i>j)return 0;
	if(a<=i && j<=b){
		return arvore[no];
	}else{
		return query(l,i,m,a,b)+query(r,m+1,j,a,b);
	}
}

int pos[MAXN];
Query Q[MAXN];
int ans[MAXN];
int32_t main(){
    fastio;
    int n,q;
    cin>>n>>q;
    memset(A,0,sizeof(A));
    build(1,0,n-1);
    map<int,int> m1;
//	map<int,int> m2;
	for(int i=0;i<n;i++){
		cin>>A[i];
		m1[A[i]];   	
	}
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		Query aux = {l-1,r-1,i};
		Q[i]= aux;
	}
	sort(Q,Q+q,cmp);
	int sz = 1;
	for(map<int,int>::iterator it=m1.begin();it!=m1.end();it++){
		m1[it->first]=sz++;
//		m2[sz-1]=it->first;
	}
	memset(pos,-1,sizeof(pos));
	int t =0;
	for(int R=0;R<n;R++){
		//adiciona:
		int p = pos[m1[A[R]]];   	
		
		if(p!=-1){
			att(1,0,n-1,p,-1);
		}
		
		att(1,0,n-1,R,1);
		pos[m1[A[R]]]=R;
			
		while(t<q && Q[t].r==R){
		   int l = Q[t].l;
		   int id = Q[t].id;
		   ans[id] = query(1,0,n-1,l,R);
		   t++;	   	
		}
		   	
	}
	
	for(int i=0;i<q;i++)cout<<ans[i]<<endl;
	
	
}