#include <bits/stdc++.h>
#define MAXN 15
using namespace std;

int fx,fy;
int inix,iniy;
int n,m;

int ocupied[MAXN][MAXN];
int atual=0;
int mx=-1;

int dx[] = {0,1,0,-1,0};

int check(int l,int c){
	if(l<=0 || l>n || c<=0 || c>m)return false;
	return true;
}

void solve(int l,int c){
	if(l==fx && c==fy){
	 mx = max(mx,atual);
	 return;	
	}
	for(int i=0;i<4;i++){
		int ll = l+dx[i];
		int cc = c + dx[i+1]; 	
	    if(ocupied[ll][cc] || !check(ll,cc))continue;	
		if(ll%2==0 && cc%2==0)continue;
		atual++;
		ocupied[l][c]=true;
		solve(ll,cc);
		ocupied[l][c]=false;
		atual--;
	}
}



int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  cin>>inix>>iniy;
  cin>>fx>>fy;
  memset(ocupied,false,sizeof(ocupied));	   	 
  solve(inix,iniy);	
  cout<<1+mx<<endl;
}