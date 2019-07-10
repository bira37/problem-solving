#include <bits/stdc++.h>
 
using namespace std;
 
long long PA(long long x){
	return ((x+1)*x)/2;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	long long a,b;
	long long max =0;
	cin >> a >> b;
	for(long long i=0; i<=b; i++){
		//cout << "y = " << i << endl;
		long long point = (b-i)*a;
		//cout << "x = " << point << endl;
		//cout << (i+1)*PA(point) + (point+1)*PA(i) << endl;
		max = std::max(max, (i+1)*PA(point) + (point+1)*PA(i));
	}
	cout << max << endl;
}
