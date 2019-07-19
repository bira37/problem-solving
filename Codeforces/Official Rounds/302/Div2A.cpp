#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int k;
	cin >> k;
	string s;
	cin >> s;
	
	vector<int> v;
	set<char> forb;
	for(int i=0; i< s.size(); i++){
		if(forb.count(s[i])) continue;
		forb.insert(s[i]);
		v.push_back(i);
	}
	
	if(v.size() < k){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	while(v.size() > k) v.pop_back();
	v.push_back(s.size());
	for(int i=0; i<v.size()-1; i++){
		string t;
		for(int j=v[i]; j<v[i+1]; j++) t += s[j];
		cout << t << endl;
	}
}
