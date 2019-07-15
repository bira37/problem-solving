#include <bits/stdc++.h>

using namespace std;
int n, k;

bool solve(int last){
	vector<int> num;
	num.push_back(last);
	int carry = 0;
	for(int i=0; i<n; i++){
		int curr = num.back()*k + carry;
		carry = curr/10;
		curr %= 10;
		num.push_back(curr);
	}
	if(carry != 0 || num[num.size()-2] == 0 || num.back() != last) return false;
	int ultimo = num.back();
	num.pop_back();
	reverse(num.begin(), num.end());
	num.pop_back();
	num.push_back(ultimo);
	for(int x : num) cout << x;
	cout << endl;
	return true;
}

int main(){
	cin >> n >> k;
	for(int i=1; i<=9; i++){
		if(solve(i)) return 0;
	}
	cout << "Impossible" << endl;
}