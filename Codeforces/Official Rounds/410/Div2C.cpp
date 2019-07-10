#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;
	long long v[n];
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
 
	long long ch = 0;
	bool flag;
	long long gcd;
	gcd = __gcd(abs(v[0]), abs(v[1]));
	for(int i = 2; i<n; i++){
		gcd = __gcd(gcd, abs(v[i]));
	}
	if(gcd != 1){
		cout << "YES" << endl << 0 << endl;
		return 0;
	}
	long long ans = 0;
	for(int i=0; i<n; i++) v[i] = v[i]%2;
	
	for(int i=0; i<n-1; i++){
		if(v[i] == 1){
			if(v[i+1] == 1){
				ans++;
				v[i] = 0;
				v[i+1] = 0;
			}
			else {
				ans+=2;
				v[i] = 0;
				v[i+1] = 0;
			}
		}
	}
	if(v[n-1] == 1) ans+=2;
	cout << "YES" << endl;
	cout << ans << endl;
}
