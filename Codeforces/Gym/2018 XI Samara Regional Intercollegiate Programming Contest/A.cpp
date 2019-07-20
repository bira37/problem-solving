#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int32_t main(){
	int s,g;
	cin >> s >> g;
	if(s%g || s == g){
		cout << -1 << endl;
		return 0;
	}
	int mul = s/g;
	
	cout << g << " " << s-g << endl;
}
