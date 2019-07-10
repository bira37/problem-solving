#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	string x,y;
	cin >> x >> y;
	if(x == y) cout << -1 << endl;
	else cout << max(x.size(), y.size()) << endl;
}
