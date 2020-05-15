#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){

		double a,b,c;
		cin >> a >> b >> c;
		cout << fixed << setprecision(1);
		cout << (a*2.0 + b*3.0 + c*5.0)/10.0 << endl;
	}
}
