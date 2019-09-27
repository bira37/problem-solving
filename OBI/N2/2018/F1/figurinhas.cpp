#include <iostream>
#include <set>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,c,m;
	cin>>n>>c>>m;
	set<int> S;
	for(int i=0;i<c;i++){
		int x;
		cin>>x;
		S.insert(x);
	}
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		if(S.find(x)!=S.end())S.erase(x);
	}
	cout<<S.size()<<endl;
}