#include <bits/stdc++.h>

#define int long long
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9

using namespace std;

inline int mod(int n){ return (n%1000000007); }

/* Knuth - Morris - Pratt Algorithm */
/* Failure Function for String Matching */ 

string s, t;
vector<int> pi;
vector<int> match;

void prefix(int n) {
	pi.resize(n);
	pi[0] = 0;
	for(int i = 1; i < n; i++) {
		pi[i] = pi[i-1];
		while(pi[i] > 0 && t[i] != t[pi[i]]) pi[i] = pi[pi[i]-1];
		if(t[i] == t[pi[i]]) pi[i]++;
	}
}

void matching(int n){
	int j = 0;
	for(int i=0; i<n; i++){
		while(j > 0 && s[i] != t[j]) j = pi[j-1];
		if(s[i] == t[j]) j++;
		if(j == t.size()){
			//cout << "match in " << i-t.size()+1 << endl;
			match.pb(i - (int)t.size()+1);
			j = pi[j-1];
		}
	}
}


int32_t main(){
	DESYNC;
	
	int n, k;
	cin >> n >> k;
	
	cin >> t;
	
	prefix((int)t.size());
	
	s.resize(n);
	for(int i=0; i<s.size(); i++) s[i] = '?';
	int v[k];
	for(int i=0; i<k; i++){
		cin >> v[i];
		v[i]--;
	}
	
	int p = 0;
	int p2 = 0;
	bool writing = false;
	for(int i=0; i<n; i++){
		if(p2 >= t.size()) writing = false;
		while(p < k && v[p] < i) p++;
		if(p < k && v[p] == i){
			p2 = 0;
		}
		if(i < v[0]) s[i] = '?';
		else if(p2 < t.size()){
			s[i] = t[p2++];
		}
		else {
			s[i] = '?';
		}
	}
	int ans = 1;
	for(int i = 0; i<n; i++){
		if(s[i] == '?'){
			ans = mod(ans*26LL);
		}
	}
	matching((int)s.size());
	if(match.size() < k) ans = 0;
	else {
		int x = 0;
		for(int val : match){
			if(x < k) if(val == v[x]) x++;
		}
		if(x < k) ans = 0;
	} 
	cout << ans << endl;
}