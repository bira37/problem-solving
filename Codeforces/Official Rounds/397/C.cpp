#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int k,a,b;
	cin >> k >> a >> b;
	if(a != 0 && a%k == 0 && b < k) cout << a/k << endl;
	else if(b != 0 && b%k == 0 && a < k) cout << b/k << endl;
	else if(a > k && a%k != 0 && b < k) cout << -1 << endl;
	else if(b > k && b%k != 0 && a < k) cout << -1 << endl;
	else if(b >= k && a >= k) cout << a/k + b/k << endl;
	else cout << -1 << endl;
}
