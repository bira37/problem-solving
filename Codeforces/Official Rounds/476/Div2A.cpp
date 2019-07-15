#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int k,n,s,p;
	cin >> k >> n >> s >> p;
	
	int totp = (n+s-1)/s;
	
	totp *= k;
	
	cout << (totp+p-1)/p << endl;

}
	
	