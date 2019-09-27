#include <bits/stdc++.h>
#define MAXN 110
#define ff first
#define ss second
using namespace std;

int n;
int dist[MAXN][MAXN];
int vis[MAXN][MAXN];
int mat[MAXN][MAXN];
int can(int l,int c){
	if(l>=1 && l<=n && c>=1 && c<=n)return true;
	return false;
}

struct cord{
	int x,y,d;
	cord(){}
	cord(int _x,int _y,int _d){
		x = _x;
		y = _y;
		d = _d;
	}
	
	
		
};

bool operator<(cord a,cord b){
	return  !(a.d<b.d);
}
int dx[]={0,1,0,-1,0};

int djkistra(){
	
	dist[1][1] = 0;
	priority_queue<cord> fila;
	fila.push(cord(1,1,0));
	while(true){
		cord davez = cord(-1,-1,-1);
		while(!fila.empty()){
			cord atual = fila.top();
			fila.pop();
			if(!vis[atual.x][atual.y]){
				davez = atual;
				break;
			}
		
		}
		if(davez.x==-1)break;
		
		   int l = davez.x;
	 	   int c = davez.y;
		vis[l][c] = true;
		for(int i=0;i<4;i++){
			int ll = l+dx[i];
			int cc = c+dx[i+1];
			if(can(ll,cc) && dist[ll][cc]>mat[ll][cc]+dist[l][c]){
			    dist[ll][cc] = mat[ll][cc] + dist[l][c];
				fila.push(cord(ll,cc,dist[ll][cc]));
			}
		}	
			
	}
	return dist[n][n];	
}


int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>mat[i][j];
			vis[i][j] = false;
			dist[i][j]=1000000000;
		}
	}   	
	cout<<djkistra()<<endl;
}