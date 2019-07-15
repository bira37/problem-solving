#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	multiset<char> k;
	string s;
	cin >> s;
	int ans = 0;
	for(int i=0; i<2*n-2; i++){
		if(i%2 == 0) k.insert(s[i] - 32);
		else {
			if(k.count(s[i])){
				k.erase(k.find(s[i]));
			}
			else ans++;
		}
	}
	cout << ans << endl;
}