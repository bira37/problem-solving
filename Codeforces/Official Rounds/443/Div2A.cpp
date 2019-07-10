#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	int ans = 0;
	for(int i=0; i<n; i++){
		int s,d;
		cin >> s >> d;
		while(s <= ans) s+=d;
		ans = s;
	}
	cout << ans << endl;
}
