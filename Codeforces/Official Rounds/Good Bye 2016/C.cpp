#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	long long prefix = 0;
	long long max = 10e9, min = -10e9;
	long long sum = 0;
	for(int i=0; i<n; i++){
		long long change, div;
		cin >> change >> div;
		sum += change;
		if(div == 2){
			max = std::min(max, 1899 - prefix);
		}
		else min = std::max(min, 1900 - prefix);
		prefix += change;
	}
	
	if(max < min){
		cout << "Impossible" << endl;
		return 0;
	}
	if(max == 10e9){
		cout << "Infinity" << endl;
	}
	else cout << max + sum << endl;
}
