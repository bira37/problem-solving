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
#define INF 1000000000 // 1e9
#define MAXN 55
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
	
	int M[MAXN][MAXN];
	int L,C;
	
	int agr(int l,int c,int d){
		return mod(M[l][c]+d,10);
	}
	
	int teste(int l,int c,int agora,int d){
		if(l>=0 && l<L && c<C && c>=0 && agora+1>=agr(l,c,d))return true;
		return false;
	}
	
	
	int dist[MAXN][MAXN][10];
	int visitado[MAXN][MAXN][10];
	
	int dx[]={0,0,1,-1,0};
	int dy[]={1,-1,0,0,0};
	
	struct dados{
		int l,c;
		int d;
	};
	
	bool operator<(dados a,dados b){
		return !(a.d<b.d);
	}
	
	int DJ(){
		for(int i=0;i<L;i++)
			for(int j=0;j<C;j++)
				for(int k=0;k<10;k++)
					dist[i][j][k]=INF;
		memset(visitado,false,sizeof(visitado));
		dist[0][0][agr(0,0,0)]=0;
		dados aux ={0,0,0};
		priority_queue<dados> fila;
		fila.push(aux);
		while(!fila.empty()){
		int l = fila.top().l;	   	
		int c = fila.top().c;
		int d = fila.top().d;	
		fila.pop();
		//cout<<l<<" "<<c<<" "<<d<<endl;
		visitado[l][c][agr(l,c,d)]=true;
			for(int i=0;i<5;i++){
				int ll = l +dx[i];
				int cc = c+dy[i];
				
				 if(teste(ll,cc,agr(l,c,d),d) && !visitado[ll][cc][agr(ll,cc,d+1)]){
					// cout<<ll<<" "<<cc<<" "<<dist[ll][cc][agr(ll,cc,d+1)]<<" "<<dist[l][c][agr(l,c,d)]<<endl;
					 if(dist[ll][cc][agr(ll,cc,d+1)]>1+dist[l][c][agr(l,c,d)]){
					 	//cout<<"aqui\n";
						 dist[ll][cc][agr(ll,cc,d+1)]=1+dist[l][c][agr(l,c,d)];
					 	 dados AA = {ll,cc,d+1};
					 	 fila.push(AA);
					 }
				 }  	
			}	
		
		
		}
		int minimo = INF;
		for(int i=0;i<10;i++){
			minimo=min(minimo,dist[L-1][C-1][i]);
		}
		
		return minimo;
	}

int32_t main(){
	cin>>L>>C;
	for(int i=0;i<L;i++)
		for(int j=0;j<C;j++)
			cin>>M[i][j];
	
	cout<<DJ()<<endl;
}