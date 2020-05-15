#include <bits/stdc++.h>

using namespace std;

bool check(int k, string s){
	bool flag = false;
	for(int i=0; i<__gcd(k, (int)s.size()); i++){
		if(s[i] == 'P') continue;
		int curr = i;
		curr+=k;
		curr%=(int)s.size();
		while(curr != i && s[curr] == 'R') curr = (curr+k)%(int)s.size();
		if(curr == i) flag = true;
	}
	return flag;
}

int main(){
	string s;
	cin >> s;
	int n = s.size();
	set<int> divisor;
	divisor.insert(1);
	for(int i=2; i<=sqrt(n); i++){
		if(n%i == 0){
			divisor.insert(i);
			divisor.insert(n/i);
		}
	}
	set<int> accept;
	for(set<int>::iterator it = divisor.begin(); it != divisor.end(); it++){
		if(check(*it,s)) accept.insert(*it);
	}
	int ans = 0;
	for(int i=1; i<=n-1; i++){
		if(accept.count(__gcd(i,n))) ans++;
	}
	cout << ans << endl;
}
