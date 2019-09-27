#include <bits/stdc++.h>
#define MAXN 110
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;

string M[MAXN];

int visitado[MAXN][MAXN];

int d[]={0,1,0,-1,0};

	int L,C;
	
int teste(int l,int c){
	if(l>=0 && l<L && c>=0 && c<C && M[l][c]=='H')return true;
	return false;
}

pii BFS(int I,int J){
	queue<pii> fila;
	fila.push(pii(I,J));
	int ul,uc;
	while(!fila.empty()){
		int l = fila.front().ff;
		int c = fila.front().ss;
		ul=l;
		uc=c;
		visitado[l][c]=true;
		fila.pop();
		for(int i=0;i<4;i++){
			int ll = d[i]+l;
			int cc = d[i+1]+c;
			if(teste(ll,cc) && !visitado[ll][cc]){
				fila.push(pii(ll,cc));
			}
			}
			
	}	
	return pii(ul,uc);
}


int main(){
	cin>>L>>C;
	
	memset(visitado,false,sizeof(visitado));
	
	int iniI=0,iniJ=0;
	for(int i=0;i<L;i++){
		cin>>M[i];
	}
	for(int i=0;i<L;i++){
		for(int j=0;j<(int)M[i].size();j++){
			if(M[i][j]=='o'){
				iniI=i;
				iniJ=j;
			}
		}
	}
//	cout<<iniI<<" "<<iniJ<<endl;
	pii res = BFS(iniI,iniJ);
	cout<<res.ff+1<<" "<<res.ss+1<<endl;
}