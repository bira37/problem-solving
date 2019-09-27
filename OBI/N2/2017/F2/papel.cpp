#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define MAXN 100100
#define INF 1000000010
using namespace std;
typedef pair<int,int> pii;
int main(){
	int n;
	cin>>n;
	int ant=-1;
	int aux;
	vector<int> alturas;
	alturas.push_back(0);
	for(int i=0;i<n;i++){
		cin>>aux;
		if(aux==ant)continue;
		ant=aux;
		alturas.push_back(aux);
	}
	alturas.push_back(0);
	vector<pii> eventos;
//	for(int i=0;i<alturas.size();i++) cout<<alturas[i]<<endl;
	
	for(int i=1;i<=(int)alturas.size()-1;i++){
		if(alturas[i]==-1 || alturas[i]==INF)continue;
		if(alturas[i]>alturas[i-1] && alturas[i]>alturas[i+1]){
			//é um pico;
			eventos.push_back(pii(alturas[i],+1));
		}
		if(alturas[i]<alturas[i-1] && alturas[i]<alturas[i+1]){
			eventos.push_back(pii(alturas[i],-1));
		}
	}
	vector<pii>::iterator it;
	sort(eventos.begin(),eventos.end(),greater<pii>());
	int res=2;
	int atual=1;
	for(it = eventos.begin();it!=eventos.end();it++){
	
		atual+=it->second;
	//	if(atual<2)atual=2;
		//	cout<<it->first<<" "<<atual<<endl;
		res=max(res,atual);
	}
	cout<<res<<endl;
	
}