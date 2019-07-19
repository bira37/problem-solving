#include <bits/stdc++.h>
 
using namespace std;
 
bool check(string s, string t){
	for(int i=0; i<=t.size()-s.size(); i++){
		if(s == t.substr(i, s.size())) return true;
	}
	return false;
}
 
int main(){
	int n;
	cin >> n;
	vector<string> v(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	
	sort(v.begin(), v.end(), [](const string & a, const string & b){ return a.size() <= b.size(); });
	
	for(int i=0; i<n-1; i++){
		//cout << "check " << v[i] << " and " << v[i+1] << endl;
		if(!check(v[i], v[i+1])){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for(string t : v){
		cout << t << endl;
	}
		
}
	
	
 
	
