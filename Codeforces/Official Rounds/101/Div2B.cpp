#include <bits/stdc++.h>

using namespace std;

int calcula(int lugar){
	int ans = 0;
	int inc = 1;
	for(int i=2; i<=lugar; i+=2){
		ans = lugar+inc;
		inc++;
	}
	return ans;
}

int calcula2(int lugar){
	int ans = 0;
	int inc = 2;
	for(int i=3; i<=lugar; i+=2){
		ans = lugar+inc;
		inc++;
	}
	return ans;
}

int main(){
	double x,y,a;
	int ya, aa;
	cin >> aa >> x >> ya;
	a = aa;
	y = ya;
	y /= a;
	if(y < 2.0){
		if(abs(x) < a/2.0 && abs(x) >= 0.0 && y > 0.0 && y < 1.0) cout << 1 << endl;
		else if(abs(x) < a/2.0 && abs(x) >= 0.0 && y > 1.0 && y < 2.0) cout << 2 << endl;
		else cout << -1 << endl;
	}
	else if(ya%aa == 0) cout << -1 << endl;
	else {
		int lugar = y;
		if(lugar%2 == 0){
			if(abs(x) < a && x < 0.0) cout << calcula(lugar) << endl;
			else if(abs(x) < a && x > 0.0) cout << calcula(lugar)+1 << endl;
			else cout << -1 << endl;
		}
		else {
			if(abs(x) < a/2.0) cout << calcula2(lugar) << endl;
			else cout << -1 << endl;
		}
	}
}