#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 1000
#define inf 10000000
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;

vector<pii> vizinhos[MAXN];
int dist[MAXN];
int visitado[MAXN];

void DJ(){
    for(int i=0;i<MAXN;i++)dist[i]=inf;
    dist[1]=0;
    priority_queue<pii,vector<pii>,greater<pii> > fila;
    fila.push(pii(0,1));
    while(true){
    int davez=-1;
        while(!fila.empty()){
        int atual = fila.top().ss;
        fila.pop();
        if(!visitado[atual]){
        davez=atual;
        break;
        }
        
        }
        if(davez==-1)break;
        
       visitado[davez]=true;
        for(int i=0;i<(int)vizinhos[davez].size();i++){
        int u = vizinhos[davez][i].ff;
        int d = vizinhos[davez][i].ss;
            if(dist[u]>d+dist[davez]){
            dist[u]=d+dist[davez];
            fila.push(pii(dist[u],u));
            
            }
        
        }
    
    }
    
}

int32_t main(){
    fastio;
    int n,m;
    cin>>n>>m;
    int a,b,d;
    
    for(int i=0;i<=n;i++)visitado[i]=false;
    
    for(int i=0;i<m;i++){
    cin>>a>>b>>d;
    vizinhos[a].push_back(pii(b,d));
    vizinhos[b].push_back(pii(a,d));
    }
    
    DJ();
    cout<<dist[n]<<endl;
}