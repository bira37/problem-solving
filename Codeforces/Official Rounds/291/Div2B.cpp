#include <bits/stdc++.h>
using namespace std;
 
pair<double, double> normalize(int x, int y){
	if(x == 0) return pair<double,double>(0,1);
	else if(y==0) return pair<double, double>(1,0);
	else{
		if(x < 0){
			x = -1*x;
			y = -1*y;
		}
		return pair<double, double>(1, y/(x*1.0));
	}
}
 
int main() {
	int n, x,y;
	set< pair<double, double> > m;
	cin >> n >> x >> y;
	for(int i=0; i<n; i++){
		int a,b;
		cin >> a >> b;
		m.insert(normalize(x-a, y-b));
	}
	cout << m.size() << endl;
	return 0;
}
