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
#define M   1000000007 // 1e9 + 7
#define MAXN 800100
using namespace std;
 
	int n;
	
	
	struct Flor{
		int H,B;
	};
	
	vector<Flor> flores(MAXN);
	
	int dp[MAXN];
	
	int arvore[MAXN];
	
	int cmp(Flor a,Flor b){
		if(a.H==b.H)return a.B>b.B;
		return a.H<b.H;
	}
	
	
	
	
	void att(int i,int j,int x,int valor,int no){
		
		if(i==j){
			arvore[no]=max(arvore[no],valor);
		}else{
			int meio = (i+j)/2,esquerda=2*no,direita =2*no+1;
		if(x<=meio){
			att(i,meio,x,valor,esquerda);
		}else{
			att(meio+1,j,x,valor,direita);
		}
		arvore[no]=max(arvore[esquerda],arvore[direita]);
		}
	}
	
	
	int query(int i,int j,int a,int b,int no){
			int meio = (i+j)/2,esquerda=2*no,direita =2*no+1;
		if(i>j || j<a || i>b)return -inf;
		
		if(i>=a && j<=b){
			return arvore[no];
		}else{
			int p1 = query(i,meio,a,b,esquerda);
			int p2 = query(meio+1,j,a,b,direita);
			return max(p1,p2);
		}
		
	}
	
	
	
 
int32_t main(){
	
	
	cin>>n;
	int max_H=0;   	
	for(int i=0;i<n;i++){cin>>flores[i].H;
	//cout<<flores[i].H<<" "<<i<<endl;
	max_H=max(max_H,flores[i].H);
	}
	
	for(int i=0;i<n;i++)cin>>flores[i].B;
	
	flores.resize(n);
	
//	sort(flores.begin(),flores.end(),cmp);
	
	memset(arvore,0,sizeof(arvore));
	int res=0;
	for(int i=0;i<n;i++){
	//	cout<<flores[i].H<<" "<<flores[i].B<<" "<<query(0,n-1,0,i,1)<<endl;
		dp[i]=query(0,max_H,0,flores[i].H-1,1)+flores[i].B;
		res=max(res,dp[i]);
		att(0,max_H,flores[i].H,dp[i],1);
	}
	cout<<res<<endl;
}
