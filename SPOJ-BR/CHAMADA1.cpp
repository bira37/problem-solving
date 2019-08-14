#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	cin.ignore();
	string v[n];
	for(int i=0; i<n; i++){
		getline(cin, v[i]);
	}
	sort(v,v+n);
	cout << v[k-1] << endl;
}
