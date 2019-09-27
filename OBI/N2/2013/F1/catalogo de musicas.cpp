#include <bits/stdc++.h>
#define MAXN 300100
#define pb push_back
#define int long long
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;

int  raiz = 1; 
map<string,int> id;
map<int,string> sla;
int  rev[MAXN];
int num=1;
vector<int> adj[MAXN];
int sz[MAXN];//quantas folhas tem na subarvore;
int cnt[MAXN];//tamanho da subarvore;
int custo[MAXN];
int qtd[MAXN];//quantidade de filhos;
int res[MAXN];
int vis[MAXN];

void dfs1(int v){
	if(vis[v])return;
	vis[v]=true;
	sz[v] = 0;
	if(adj[v].size()==0)sz[v]=1;
	cnt[v] = 0;
	qtd[v]=0;
	for(int i=0;i<(int)adj[v].size();i++){
		int u = adj[v][i];
		if(vis[u])continue;
		dfs1(u);
		qtd[v]++;
		cnt[v]+=cnt[u] + (v!=1 ? sz[u] : 0);
		//     tamanho do filho + repete o pai + /;
		sz[v]+=sz[u];
	}
	cnt[v]+=sz[v]*rev[v];
}

void dfs2(int v,int p){
	vis[v]=true;
   if(v==1){
	   res[v] = cnt[v];
   	   for(int i=0;i<(int)adj[v].size();i++){
   	   		if(vis[adj[v][i]])continue;
			  dfs2(adj[v][i],1);
		  }
   }else{  
	  //o que muda do pai : 
	  //-sz[u]*rev[v] + (../)*((num-1)-sz[v]) + sz[p]*rev[p];
	  
	  res[v] = res[p] - sz[v]*(rev[v]+1) + 3*(sz[1] - sz[v]); 
      
	 
	//  cout<<v<<" "<<sla[v]<<" "<<res[v]<<endl;
	  for(int i=0;i<(int)adj[v].size();i++){
           if(vis[adj[v][i]])continue;
		   dfs2(adj[v][i],v);
	   } 
	   if(adj[v].size()==0)res[v]=1e10;
	   	    
   }	
	
	
}



int32_t main(){
		int n;
	 cin>>n;
	 sla[1] = "";
	 rev[1] = 0;
	 for(int i=0;i<n;i++){
		 string s;
		 cin>>s;
		 string t="";
		 vector<int> ordem;
		 for(int j=0;j<s.size();j++){
			 if(s[j]=='/'){
		        if(id.count(t)==0){
				id[t]=++num;		 
		       	rev[num] = t.size();
		       	sla[num] = t;
				}
				ordem.pb(id[t]);
				t="";		 
			 }else t+=s[j];
		 }
		 if(t!=""){
			 if(id.count(t)==0){
				 id[t]=++num;
				 rev[num] = t.size();
				 sla[num] = t;
			 }
			 ordem.pb(id[t]);
		 }
		 adj[1].pb(ordem[0]);
		 for(int j=0;j<(int)ordem.size() - 1;j++){
			 adj[ordem[j]].pb(ordem[j+1]); // ???
		 }
	 }
	 memset(vis,false,sizeof(vis));
	 dfs1(1);
	 memset(vis,false,sizeof(vis));
	 dfs2(1,1);
	 int mn = 1e15;
	 for(int i=1;i<=num;i++){
		 mn = min(mn,res[i]);
	 } 
	 cout<<mn<<endl;
	 
}