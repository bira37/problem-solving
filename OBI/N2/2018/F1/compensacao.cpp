#include <iostream>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int m,n;
	cin>>m>>n;
	vector<int> saldo(n+1,0);
	int sum=0;
	for(int i=0;i<m;i++){
		int x,v,y;
		cin>>x>>v>>y;
		saldo[x]-=v;
		saldo[y]+=v;
		sum+=v;
	}
	int other = 0;
	for(int i=1;i<=n;i++){
		if(saldo[i]>0)other+=saldo[i];
	}
	if(other==sum){
		cout<<"N"<<endl;
		cout<<sum<<endl;
	}else{
		cout<<"S"<<endl;
		cout<<other<<endl;
	}
}