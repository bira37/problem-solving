#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define int long long // LEMBRAR DE TROCAR CASO PROBLEMA DE MEMORIA
#define pii pair<int,int>
#define ieps (int) 1e6
#define eps (int) 1e9
#define mp make_pair
#define pb push_back
#define piii pair<pii ,int>
 
 
 
int32_t main(){
ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	int n;
	cin>>n;
	vector<piii > v;
	for(int i = 0 ; i < n ; i ++){
		int x , y;
		cin>>x>>y;
		v.pb(piii(pii(x , y) , 0));
		v.pb(piii(pii(y , x) , 1));
	}
	sort(v.begin() , v.end());
	set<int> opt;
	int last = -1;
	for(int i = 0 ; i < v.size() ; i++){
		if(v[i].S == 1){
			if(last >= v[i].F.S){
				continue;
			}
			else opt.insert(v[i].F.F);
			last = v[i].F.F;
		}
	}
	cout<<opt.size()<<endl;
	for(auto p : opt){
		cout<<p<<" ";
	}
}
