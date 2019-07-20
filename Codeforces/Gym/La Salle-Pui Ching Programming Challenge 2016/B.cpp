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
 
 
int32_t main(){
	long double ax , by , cz;
	long double x , y, z;
	cin>>x>>y>>z;
	ax = 100.00000000001/x*1.00000000 , by = 100.0000000001/y*1.0000000,  cz  = 100.0000000001/z*1.0000000000;
	//cout<<fixed<<setprecision(90)<<" "<<ax+by+cz<<endl;
	if(ax + by + cz <= 100.000000000) cout<<"Yes\n";
	else cout<<"No\n";
}
