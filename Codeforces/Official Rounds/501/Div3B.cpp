#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
 
bool check(string a, string b){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a != b;
}
 
int32_t main(){
	int n;
	cin >> n;
	string s;
	string t;
	cin >> s >> t;
	if(check(s,t)){
		cout << -1 << endl;
		return 0;
	}
	vector<int> ans;
	for(int i=0; i<n; i++){
		//fixing t[i]
		int pos = -1;
		for(int j=i; j<s.size(); j++){
			if(s[j] == t[i]){
				pos = j;
				continue;
			}
		}
		for(int j = pos; j>i; j--){
			swap(s[j], s[j-1]);
			ans.pb(j-1);
		}
	}
	cout <<ans.size() << endl;
	for(int x : ans) cout << x+1 << " ";
	cout << endl;
}
