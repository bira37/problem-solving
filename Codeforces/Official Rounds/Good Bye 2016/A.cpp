#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	int max = 240;
	int n,t;
	cin >> n >> t;
	int time = max - t;
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(5*i <= time){
			ans++;
			time -= 5*i;
		}
		else break;
	}
	cout << ans << endl;
}
