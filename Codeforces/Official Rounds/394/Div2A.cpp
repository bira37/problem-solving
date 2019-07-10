#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	if(n == 0 && m == 0) cout << "NO" << endl;
	else if(abs(n-m) <= 1) cout << "YES" << endl;
	else cout << "NO" << endl;
}
