#include <bits/stdc++.h>
#define MAXN 550
#define INF 123456789
#define ss second
#define ff first
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;

typedef pair<ll,ll> pii;

ll n,m,E,S;

struct dados
{
	int v,dist,t;
};

bool operator<(dados a,dados b){
	return !(a.dist<b.dist);
}

ll visitado[MAXN][3];

ll dist[MAXN][3];
vector<pii> vizinhos[MAXN];

inline ll mod(ll a,ll b){ll r = a%b;if(r<0)r+=b;return r;}

int flag = false;

ll DJ(){
	ll mini = INF;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<3;j++){
			visitado[i][j]=false;
			dist[i][j]=INF;
		}
	}
	
	dist[E][0]=0;
	dados aux = {E,0,0};
	priority_queue<dados> fila; 
	fila.push(aux);  
	while(true){
		int davez=-1;
		int t;
		while(!fila.empty()){
			int atual = fila.top().v;
			t = fila.top().t;
			fila.pop();
			if(!visitado[atual][t]){
				davez=atual;
				break;
			}	
			
		}
		if(davez==-1)break;
	//	cout<<davez<<" "<<t<<endl;
		visitado[davez][t]=true;
		   if(davez==S){
		   		flag = true;
			   mini=min(mini,dist[davez][t]);
		   }	
	for(int i=0;i<(int)vizinhos[davez].size();i++){
			int u = vizinhos[davez][i].ff;
			int T = vizinhos[davez][i].ss;
			if(T==0 && mod(t,3)==0)continue;
			if(T==1 && mod(t,3)!=0)continue;
			if(dist[u][mod(t+1,3)]>dist[davez][t]+1){
				dist[u][mod(t+1,3)]=dist[davez][t]+1;
				dados AA = {u,dist[u][mod(t+1,3)],mod(t+1,3)};
				fila.push(AA);
			}
		}
	
		
		
	}
	
	
	return mini;
}


int32_t main(){
	fastio;
	cin>>n>>E>>S>>m;
	
	ll a,b,c;
	
	for(ll i=0;i<m;i++){
		cin>>a>>b>>c;
		vizinhos[a].push_back(pii(b,c));
	}
	
	a= DJ();
	if(flag){
		cout<<a<<endl;
	}else cout<<"*\n";
	
}