#include <bits/stdc++.h>

using namespace std;

int main(){
	int x1,x2,x3,x4,y1,y2,y3,y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	if(x2 < x3 || y2 < y3 || x4 < x1 || y4 < y1) cout << 0 << endl;
	else cout << 1 << endl;
}

