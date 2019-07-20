#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int32_t main(){
	int n;
	cin >> n;
	set<int> ans;
	int curr = 2;
	if(n == 3){
		cout << "2 5 63" << endl;
		return 0;
	}
	n-=2;
	ans.insert(3);
	ans.insert(29997);
	while(curr < 30000 - curr && n > 1){
		n-=2;
		ans.insert(curr);
		ans.insert(30000 - curr);
		curr += 2;
	}
	curr = 9;
	while(curr < 30000 - curr && n > 1){
		n-=2;
		ans.insert(curr);
		ans.insert(30000 - curr);
		curr += 3;
		while(curr%2 == 0) curr += 3;
	}
	curr = 5;
	while(curr < 30000 - curr && n > 1){
		n-=2;
		ans.insert(curr);
		ans.insert(30000 - curr);
		curr += 5;
		while(curr%2 == 0 || curr%3 == 0) curr += 5;
	}
	if(n == 1) ans.insert(30000);
	for(int x : ans){
		if(x == *ans.begin()) cout << x;
		else cout << " " << x;
	}
	cout << endl;
}
