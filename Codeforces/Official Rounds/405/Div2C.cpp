#include <bits/stdc++.h>
 
using namespace std;
 
int k = 0;
string generate_name(){
	if(k >= 26){
		string ans =  "A";
		ans += ('a' + k%26);
		k++;
		return ans;
	}
	string ans;
	ans += 'A'+(char)k;
	k++;
	return ans;
}
 
int main(){
	int n,m;
	cin >> n >> m;
	vector<string> ans;
 
	for(int i=0; i<m-1; i++){
		ans.push_back(generate_name());
	}
	for(int i=m-1; i<n; i++){
		string x;
		cin >> x;
		if(x == "YES") ans.push_back(generate_name());
		else ans.push_back(ans[i-(m-1)]);
	}
	
	for(int i=0; i<ans.size(); i++){
		if(!i) cout << ans[i];
		else cout << " " << ans[i];
	}
	
	cout << endl;
}
