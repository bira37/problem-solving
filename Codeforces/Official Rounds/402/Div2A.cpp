#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	
	int n;
	int a[6], b[6];
	cin >> n;
	
	for(int i=0; i<6; i++){
		a[i] = 0;
		b[i] = 0;
	}
 
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		a[x]++;
	}
 
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		b[x]++;
	}
 
	int ans = 0;
	
	for(int i=0; i<6; i++){
		if((a[i]+b[i]) % 2){
			cout << -1 << endl;
			return 0;
		}
	}
	
	for(int i=0; i<6; i++){
		int aux = (a[i]+b[i])/2;
		ans += abs(aux - b[i]);
	}
 
	ans/=2;
	
	cout << ans << endl;	
 
}
