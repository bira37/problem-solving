#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	bool vis[100001];
	for(int i=0; i<100001; i++){
		vis[i] = false;
	}
	
	int n;
	cin >> n;
	int ans = 0;
	int current = 0;
	for(int i =0; i< 2*n; i++){
		int x;
		cin >> x;
		if(vis[x]){
			vis[x] = false;
			current--;
		}
		else{
			vis[x] = true;
			current++;
		}
		ans = max(ans, current);
	}
	
	cout << ans << endl;
}
