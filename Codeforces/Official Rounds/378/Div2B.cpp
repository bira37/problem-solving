#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	int left[n], right[n];
	long long sl = 0,sr = 0;
	for(int i=0; i<n; ++i){
		cin >> left[i] >> right[i];
		sl += left[i];
		sr += right[i];
	}
	long long maximize = abs(sl - sr);
	int res = -1;
	for(int i=0; i<n; ++i){
		long long al = sl;
		long long ar = sr;
		al = al - left[i] + right[i];
		ar = ar - right[i] + left[i];
		if(abs(al - ar) > maximize){
			res = i;
			maximize = abs(al - ar);
		}
	}
	cout << res+1 << endl;
}
