#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n,x,y;
	cin >> n >> x >> y;
	long long lcm = (x*y)/__gcd(x,y);
	x = lcm/x;
	y = lcm/y;
	
	while(n--){
		long long a;
		cin >> a;
		
		long long l = 0, r = (long long)1e17;
		long long ans = 0;
		while(l <= r){
			long long m = (l+r)>>1;
			if(m/x + m/y >= a){
				ans = m;
				r = m -1;
			}
			else l = m+1;
		}
		if(ans%x == 0 && ans%y == 0) cout << "Both" << endl;
		else if(ans%x == 0) cout << "Vanya" << endl;
		else cout << "Vova" << endl;
	}
}