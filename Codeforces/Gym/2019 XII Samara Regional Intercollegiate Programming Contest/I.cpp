#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
 
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a,b;
	cin >> a >> b;
	int rem = (a%b);
	int tot = (a*a - b*b - rem*rem);
	cout << (tot+b-1)/b + rem << endl;
}
