#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define endl '\n'
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;

inline int mod(int n){ return (n%1000000007); } 

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

bool solve(int * cntp, int * cnt){
	int falta = 0;
	for(int i=0; i<26; i++){
		//cout << "letter " << char('a' + i) << "p = " << cntp[i] << " s= " << cnt[i] << endl; 
		falta += max(0, cntp[i] - cnt[i]);
	}
	//cout << "interrogation is " << cnt[26] << endl;
	//cout << "falta " << falta << endl;
	if(falta <= cnt[26]) return true;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	string p;
	cin >> s;
	cin >> p;
	int n = s.size();
	int k = p.size();
	if(n < k){
		cout << 0 << endl;
		return 0;
	}
	int cntp[26];
	for(int i=0; i<26; i++) cntp[i] = 0;
	for(char c : p) cntp[c - 'a']++;
	int cnt[27];
	for(int i=0; i<27; i++) cnt[i] = 0;
	int ans = 0;
	for(int i=0; i<k; i++){
		if(s[i] == '?') cnt[26]++;
		else cnt[s[i] - 'a']++;
	}
	//cout << "for " << k-1 << " " << endl;
	ans += solve(cntp, cnt);
	for(int i=k; i<n; i++){
	//	cout << "for " << i << " " << endl;
		if(s[i-k] == '?') cnt[26]--;
		else cnt[s[i-k] - 'a']--;
		if(s[i] == '?') cnt[26]++;
		else cnt[s[i] - 'a']++;
		ans += solve(cntp, cnt);
	}
	cout << ans << endl;
}