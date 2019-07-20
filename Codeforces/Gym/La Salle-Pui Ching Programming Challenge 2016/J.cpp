#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int x,y,ax,ay,bx,by;
	cin >> x >> y >> ax >> ay >> bx >> by;
	
	bool p1 = false, p2 = false;
	
	if(ax > x || ay > y){
		cout << "No" << endl << "No" << endl;
		return 0;
	}
	
	if(ax + bx <= x && ay <= y && by <= y) p1 = true;
	
	if(ay + by <= y && ax <= x && bx <= x) p1 = true;
	
	if(by <= y && (x - ax) >= 2*bx) p2 = true;
	
	if(bx <= x && (y - ay) >= 2*by) p2 = true;
	
	if(p1) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	if(!p2) cout << "Yes" << endl;
	else cout << "No" << endl;
	
}
