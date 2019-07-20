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
#define INF 1e18
#define ROOT 1
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
int32_t main(){
	DESYNC;
	string s,t;
	int h[26];
	for(int i=0; i<26; i++) h[i] = 0;
	cin >> s >> t;
	for(char c : s) h[c-'a']++;
	for(char c : t) h[c-'a']++;
	int odd = 0, even = 0;
	for(int i=0; i<26; i++){
	  if(h[i]%2) odd++;
	  else even++;
	}
	if((s.size()+t.size())%2 == 1 && odd == 1) cout << "YES" << endl;
	else if(odd == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}
 
