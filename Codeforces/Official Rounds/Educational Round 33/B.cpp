#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int ans;
	for(int i=1; i<=n; i++){
		if(n%i == 0){
			bool flag = false;
			for(int j=1; j<=15; j++){
				if(((1<<j)-1)*(1<<(j-1)) == i){
					ans = i;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}