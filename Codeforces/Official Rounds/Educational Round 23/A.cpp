#include <bits/stdc++.h>
#define ff first
#define ss second
 
using namespace std;
 
int main(){
	pair<int,int> ini, fim;
	pair<int, int> move;
	
	cin >> ini.ff >> ini.ss >> fim.ff >> fim.ss;
	cin >> move.ff >> move.ss;
		
	int difX = abs(fim.ff - ini.ff);
	int difY = abs(fim.ss - ini.ss);
 
	if(difX % move.ff || difY % move.ss) cout << "NO" << endl;
	else {
		int moveX = difX/move.ff;
		int moveY = difY/move.ss;
	
		if(abs(moveX - moveY) % 2) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
 
}
