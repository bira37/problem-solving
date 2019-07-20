#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int32_t main(){
	string s;
	cin >> s;
	if(s.size() < 26){
		set<char> pool;
		for(char c : s) pool.insert(c);
		for(int i=0; i<26; i++){
			if(pool.count(char('a'+i))) continue;
			s += char('a'+i);
			cout << s << endl;
			return 0;
		}
	}
	else {
		set<char> pool;
		for(char c : s) pool.insert(c);
		while(s.size() > 0){
			char curr = s.back();
			curr++;
			while(curr <= 'z'){
				if(pool.count(curr)) curr++;
				else{
					s.back() = curr;
					cout << s << endl;
					return 0;
				}
			}
			pool.erase(s.back());
			s.pop_back();
		}
		cout << -1 << endl;
	}
}
		
