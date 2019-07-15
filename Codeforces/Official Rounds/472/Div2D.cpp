#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n;
	cin >> n;
	int below[n];
	int under[n];
	cin >> under[0];
	below[0] = 0;
	int tot = 0;
	vector<int> change;
	for(int i=1; i<n; i++){
		cin >> under[i];
		below[i] = below[i-1] + (under[i-1] - under[i]);
		tot += below[i];
		change.push_back(i);
		if(below[i] < 0){
			while(below[i] < 0){
				tot += (i - change.back() + 1);
				change.pop_back();
				below[i]++;
			}
		}
	}
	cout << tot << endl;
}