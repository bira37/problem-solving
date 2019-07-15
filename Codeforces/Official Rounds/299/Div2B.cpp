#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> num;

void gen(int n){
	num.push_back(n);
	if(10*n + 4 <= 1000000000) gen(10*n + 4);
	if(10*n + 7 <= 1000000000) gen(10*n + 7);
}

int32_t main(){
	int n;
	cin >> n;
	gen(0);
	sort(num.begin(), num.end());
	
	cout << lower_bound(num.begin(), num.end(), n) - num.begin() << endl;
}