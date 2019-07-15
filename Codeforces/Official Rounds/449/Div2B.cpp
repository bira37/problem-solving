#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define ii pair<int, int>
#define int long long
using namespace std;

int str_to_int(string s){
	int ans = 0;
	for(int i=0; i<s.size(); i++){
		ans = (10*ans + (s[i] -'0'));
	}
	return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	int ans = 0;
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		string num = to_string(i);
		string rnum = num;
		reverse(rnum.begin(), rnum.end());
		num +=rnum;
		//cout << num << " " << str_to_int(num) << endl;
		ans += str_to_int(num);
		ans %= m;
	}
	cout << ans << endl;
}