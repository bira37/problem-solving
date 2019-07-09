#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	
	int min = 0x3f3f3f3f;
	int n,m;
	cin >> n >> m;
	int a,b;
	for(int i =0; i<m; ++i){
		cin >> a >> b;
		if((b-a) < min) min = b-a;
	}
	min++;
	cout << min << endl;
	
	for(int i=0; i<n; ++i){
		if(!i) cout << i%min;
		else cout << " " << i%min;
	}
	cout << endl;
}
