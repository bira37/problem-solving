#include<bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define ff first
#define ss second
#define pb(x) push_back(x)
#define td(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
 
bool check(vector<char> & perm, string & s){
	//cout << "checking ";
	//for(char c : perm) cout << c;
	//cout << endl << s << endl;
	vector<bool> vis(s.size(), false);
	int max_i = -1;
	for(int i=0; i<s.size(); i++){
		if(vis[i]) continue;
		if(perm[2] == s[i]){
			vis[i] = true;
			max_i = i;
		}
	}
	for(int i=max_i +1; i<s.size(); i++){
		if(vis[i]) continue;
		if(perm[1] == s[i]){
			vis[i] = true;
		}
	}
	max_i = -1;
	for(int i=0; i<s.size(); i++){
		if(vis[i]) continue;
		if(perm[1] == s[i]){
			vis[i] = true;
			max_i = i;
		}
	}
	for(int i=max_i +1; i<s.size(); i++){
		if(vis[i]) continue;
		if(perm[0] == s[i]){
			vis[i] = true;
		}
	}
	for(int i=0; i<s.size(); i++) if(!vis[i]) return false;
	return true;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	vector<char> perm;
	perm.pb('B');
	perm.pb('G');
	perm.pb('R');
	set<char> ss;
	string s;
	cin >> s;
	for(char x : s) ss.insert(x);
	if(ss.size() < 3){
		cout << "YES" << endl;
		return 0;
	}
	do{
		if(check(perm, s)){
			cout << "YES" << endl;
			return 0;
		}
	
	} while(next_permutation(perm.begin(), perm.end()));
	
	cout << "NO" << endl;
	
 }
	
