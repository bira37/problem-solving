#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	string x;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
	}
	cout << (n%2 ? "contest" : "home") << endl;
}
