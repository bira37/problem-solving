#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
 
int32_t main(){
	int ans = 4;
	int n,m, k;
	cin >> n >> m >> k;
	map < pair<int ,int>, bool > mapa;
	for(int i=0; i<k; i++){
		int x,y;
		cin >> x >> y;
		mapa[make_pair(x,y)] = true;
	}
	if(n == 1 && m == 1){
		ans = 1;
		if(mapa[make_pair(1,1)]) ans--;
	}
	else if(n == 1){
		ans = 2;
		if(mapa[make_pair(1,1)]) ans--;
		if(mapa[make_pair(1,m)]) ans--;
	}
	else if(m == 1){
		ans = 2;
		if(mapa[make_pair(1,1)]) ans--;
		if(mapa[make_pair(n,1)]) ans--;
	}
	else {
		ans = 4;
		if(mapa[make_pair(1,1)]) ans--;
		if(mapa[make_pair(n,m)]) ans--;
		if(mapa[make_pair(1,m)]) ans--;
		if(mapa[make_pair(n,1)]) ans--;
	}
 
	cout << ans << endl;
 
}
