#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	int v[212345];
	for(int i=0; i<212345; i++) v[i] = 0;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		v[x]++;
	}
	
	int ans = 0;
	
	for(int i=0; i<212345; i++) ans += v[i]/2;
	
	cout << ans/2 << endl;
}
