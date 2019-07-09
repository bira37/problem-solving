#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long long n;
	cin >> n;
	long long c[3][3], b[3][3];
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			c[i][j] = 0x7fffffffffffffff;
			b[i][j] = 0x7fffffffffffffff;
		}
	}
	long long reix, reiy;
	cin >> reix >> reiy;
	for(int i=0; i<n; ++i){
		char p;
		long long x,y;
		cin >> p >> x >> y;
		long long posx, posy;
		posx = x - reix;
		posy = y - reiy;
		if(posx == 0 || posy == 0){
			long long dist = abs(max(abs(posx), abs(posy)));
			posx = (posx != 0 ? posx/dist : 0);
			posy = (posy != 0 ? posy/dist : 0);
			if(p == 'B'){
				if(dist < b[posx+1][posy+1]) b[posx+1][posy+1] = dist;
			}
			else if(dist < c[posx+1][posy+1]) c[posx+1][posy+1] = dist;
		}
		else if(abs(posx) == abs(posy)){
			long long dist = abs(posx);
			posx = posx/dist;
			posy = posy/dist;
			if(p == 'R'){
				if(dist < b[posx+1][posy+1]) b[posx+1][posy+1] = dist;
			}
			else if(dist < c[posx+1][posy+1]) c[posx+1][posy+1] = dist;
		}
	}
	bool flag = false;
	for(int i=0; i<3; ++i){
		 for(int j=0; j<3; ++j){
			if(c[i][j] < b[i][j]) flag = true;
		 }
	}
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}
