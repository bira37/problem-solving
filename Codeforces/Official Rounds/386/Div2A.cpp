#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long long a,b,c;
	cin >> a >> b >> c;
	
	long long ans = min(a, min(b/2, c/4));
	
	cout << 1*ans + 2*ans + 4*ans << endl;
}
