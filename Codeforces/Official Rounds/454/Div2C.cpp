#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define M 1000000007
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;

//////////////////////////////////////////////STL - Ordered Set////////////////////////////////////////////
typedef tree<
int, //change for pair<int,int> to use like multiset
null_type,
less<int>, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int differ = 0;
//////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	set<char> let;
	for(int i=0; i<26; i++) let.insert(char('a'+i));
	int n;
	cin >> n;
	int ans = 0;
	for(int i=0; i<n-1; i++){
		char c;
		string s;
		cin >> c >> s;
		if(c == '?'){
			//cout << "guess" << endl;
			if(let.size() == 1) ans++;
			if(let.count(s[0])) let.erase(let.find(s[0]));
		}
		else if(c == '.'){
			//cout << "nada" << endl;
			for(char k : s) if(let.count(k)) let.erase(let.find(k));
		}
		else if(c == '!'){
			//cout << "shock" << endl;
			if(let.size() == 1) ans++;
			else {
				set<char> tira;
				for(char k : s) tira.insert(k);
				for(int j=0; j<26; j++){
					if(!tira.count(char('a'+j))){
					//	cout << "tirei " << char('a'+j) << endl;
						if(let.count(char('a'+j))) let.erase(let.find(char('a'+j)));
					}
				}
			}
		}
	}
	char c;
	string s;
	cin >> c >> s;
	cout << ans << endl;
}