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
#define MAXN 100100
using namespace std;
typedef pair<int,int> pii;
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
int n,m;

struct dado{
	int mn,mx,idmn,idmx;
		
};
dado arvore[4*MAXN];
int A[MAXN];

void build(int no,int i,int j){
    if(i==j){
	   arvore[no].mn = A[i];
	   arvore[no].mx = A[i];
	   arvore[no].idmn = i;
	   arvore[no].idmx = i;	   
     }else{
		 int l = 2*no,r = 2*no+1,m = (i+j)/2;
		 build(l,i,m);
		 build(r,m+1,j);
		 
		if(arvore[l].mn < arvore[r].mn){
		  arvore[no].mn = arvore[l].mn;
		  arvore[no].idmn = arvore[l].idmn;	
		}else{
			arvore[no].mn = arvore[r].mn;
		  arvore[no].idmn = arvore[r].idmn;	
		}
		if(arvore[l].mx>arvore[r].mx){
			arvore[no].mx = arvore[l].mx;
		  arvore[no].idmx = arvore[l].idmx;	
		}else{
			arvore[no].mx = arvore[r].mx;
		  arvore[no].idmx = arvore[r].idmx;	
		}
		
		
	 }	
}

void att(int no,int i,int j,int pos,int val){
	if(i==j){
		arvore[no].mn = min(arvore[no].mn,val);
		arvore[no].mx = max(arvore[no].mx,val);
	}else{
		 int l = 2*no,r = 2*no+1,m = (i+j)/2;
		if(pos<=m){
			att(l,i,m,pos,val);
		}else att(r,m+1,j,pos,val);
		
		
		if(arvore[l].mn < arvore[r].mn){
		  arvore[no].mn = arvore[l].mn;
		  arvore[no].idmn = arvore[l].idmn;	
		}else{
			arvore[no].mn = arvore[r].mn;
		  arvore[no].idmn = arvore[r].idmn;	
		}
		if(arvore[l].mx>arvore[r].mx){
			arvore[no].mx = arvore[l].mx;
		  arvore[no].idmx = arvore[l].idmx;	
		}else{
			arvore[no].mx = arvore[r].mx;
		  arvore[no].idmx = arvore[r].idmx;	
		}
		
	}
}

pii getmx(int no,int i,int j,int a,int b){
//	cout<<i<<" "<<j<<" "<<a<<" "<<b<<endl;
	if(i>b || j<a || i>j || a>b || a<0)return pii(-1,0);
	
	if(a<=i && j<=b){
		return pii(arvore[no].mx,arvore[no].idmx);
	}else{
		 int l = 2*no,r = 2*no+1,m = (i+j)/2;
		 pii op1 = getmx(l,i,m,a,b);
		 pii op2 = getmx(r,m+1,j,a,b); 
		if(op1.ff>op2.ff)return op1;
		else return op2;
	}
}

pii getmn(int no,int i,int j,int a,int b){
	//cout<<i<<" "<<j<<" "<<a<<" "<<b<<endl;
	if(i>b || j<a || i>j || a>b || a<0)return pii(1000010,0);
	
	if(a<=i && j<=b){
		return pii(arvore[no].mn,arvore[no].idmn);
	}else{
		 int l = 2*no,r = 2*no+1,m = (i+j)/2;
		 pii op1 = getmn(l,i,m,a,b);
		 pii op2 = getmn(r,m+1,j,a,b); 
		if(op1.ff<op2.ff)return op1;
		else return op2;
	}
}

int32_t main(){
//	fastio;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>A[i];
	build(1,0,n-1);
	while(m--){
		int op,a,b;
		cin>>op>>a>>b;
		if(op==1){
			b--;
			att(1,0,n-1,b,a);
		}else{
			a--;
			b--;
           pii s1 = getmx(1,0,n-1,a,b);
		   pii s2 = getmn(1,0,n-1,a,b);
		//   cout<<s1.ff<<" "<<s2.ff<<" "<<s1.ss<<" "<<s2.ss<<endl;
		   int op1 = s1.ff;
		   op1-=min(getmn(1,0,n-1,a,s1.ss-1).ff,getmn(1,0,n-1,s1.ss+1,b).ff);
		   int op2 = - s2.ff;
		   op2+=max(getmx(1,0,n-1,a,s2.ss-1).ff,getmx(1,0,n-1,s2.ss+1,b).ff);
		   cout<<max(op1,op2)<<endl;
		}
	}
}