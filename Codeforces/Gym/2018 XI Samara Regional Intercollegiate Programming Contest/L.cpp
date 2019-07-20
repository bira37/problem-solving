#include <bits/stdc++.h>
#define ii pair<int,int>
#define ff first
#define ss second
 
using namespace std;
 
vector<int> nxt[26];
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string s;
	int q;
	cin >> s;
	cin >> q;
	
	for(int i=0; i<s.size(); i++){
		nxt[s[i] - 'a'].push_back(i);
	}
	
	for(int i=0; i<26; i++) sort(nxt[i].begin(), nxt[i].end());
	
	vector<int> last_ans;
	vector<bool> prints;
	
	while(q--){
		string op;
		cin >> op;
		
		bool ans = true;
		if(op == "push"){
			char c;
			cin >> c;
			int curr = -1;
			if(last_ans.size() > 0) curr = last_ans.back();
			
			int pos = upper_bound(nxt[c-'a'].begin(), nxt[c - 'a'].end(), curr) - nxt[c - 'a'].begin();
			if(pos == nxt[c - 'a'].size()){
				ans = false;
				last_ans.push_back(3123456);
			}
			else {
				last_ans.push_back(nxt[c - 'a'][pos]);
			}
			
			prints.push_back(ans);
		}
		else {
			last_ans.pop_back();
			prints.pop_back();
			if(prints.size() > 0) ans = prints.back();
		}
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
			
	
