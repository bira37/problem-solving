#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;

struct dado{
	int x;
	int y1,y2;
	int tipo;
};
bool operator < (dado a,dado b){
	return a.x<b.x;
}

vector<dado> dados;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 	int n;
 	cin>>n;
 	 for(int i=0;i<n;i++){
	 int x1,x2,y1,y2;
	 	 cin>>x1>>y2>>x2>>y1;
	 	 dado a = {x1,y1,y2,0};
		 dado b = {x2,y1,y2,1};
		 dados.pb(a);
		 dados.pb(b);	 	 
 	 }
 	 sort(dados.begin(),dados.end());
 	 int resp=0;
 	 map<int,int> mapa;
 	 for(int i=0;i<2*n;i++){
	  if(dados[i].tipo==0){
		  mapa[dados[i].y1]=0;
		  mapa[dados[i].y2]=1;
	  }else{
		  if(mapa[dados[i].y1]==0)resp++;
		  map<int,int>::iterator it = mapa.find(dados[i].y1);
	  	  it--;
	  		it->second=1;
	  		mapa.erase(dados[i].y1);
	  		mapa.erase(dados[i].y2);
	    }	  
     }
     cout<<resp<<endl;
}