#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int n1 = 0, n2 = 0, sum = 0;
	int p = 0;
	while(p < s.size() && s[p] != '+') n1++, p++;
	p++;
	while(p < s.size() && s[p] != '=') n2++, p++;
	p++;
	while(p < s.size()) sum++, p++;
	if(n1+n2 == sum){
		cout << s << endl;
		return 0;
	}
	else if(n1+n2 == sum+2){
		if(n1 > 1) n1--;
		else n2--;
		sum++;
	}
	else if(n1+n2 == sum-2){
		sum--;
		n1++;
	}
	else {
		cout << "Impossible" << endl;
		return 0;
	}
	
	if(n1 == 0 || n2 == 0 || sum == 0) cout << "Impossible" << endl;
	else {
		for(int i=0; i<n1; i++) cout << '|';
		cout << '+';
		for(int i=0; i<n2; i++) cout << '|';
		cout << '=';
		for(int i=0; i<sum; i++) cout << '|';
		cout << endl;
	}
}