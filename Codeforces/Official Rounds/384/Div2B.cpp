#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long long n, k;
	long long ans;
 
	cin >> n >> k;
	ans = 1;
	while(k>0 && k%2 == 0){
		ans++;
		k = k/2;
	}
	
	cout << ans << endl;
}   
