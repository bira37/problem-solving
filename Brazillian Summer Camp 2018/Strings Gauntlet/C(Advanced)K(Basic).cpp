#include <bits/stdc++.h>

using namespace std;

struct Z{
	vector<int> z;
	
	Z() = default;
	
	void make(string s){
		int n = s.size();
		z.resize(n);
		z[0] = 0;
		int l = 0, r = 0;
		for(int i=1; i<n; i++){
			if(i > r){
				l = i;
				r = i;
			}
			z[i] = min(z[i-l], r-i+1);
			while(i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
			if(i + z[i] > r){
				l = i;
				r = i + z[i]-1;
			}
		}
	}
};

int main(){
	string s,t;
	cin >> s >> t;
	int k;
	cin >> k;
	Z pz, sz;
	
	string pre = t + s;
	reverse(t.begin(), t.end());
	reverse(s.begin(), s.end());
	string suf = t + s;
	int offset = t.size();
	
	pz.make(pre);
	sz.make(suf);
	vector<int> ans;
	for(int i=t.size(); i<pre.size(); i++){
		int rev = (i - offset);
		rev += (offset-1);
		rev = s.size() - rev;
		rev += offset;
		rev--;
		if(i + offset > pre.size()) break;
		if(offset - (pz.z[i]+sz.z[rev]) <= k) ans.push_back(i-offset+1);
	}
	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++){
		if(i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}		

