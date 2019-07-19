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
	
	int t;
	cin >> t;
	
	int mir[26];
	memset(mir, 0, sizeof mir);
	mir[0] = 1;
	mir[7] = 1;
	mir[8] = 1;
	mir[12] = 1;
	mir[14] = 1;
	mir[19] = 1;
	mir[20] = 1;
	mir[21] = 1;
	mir[22] = 1;
	mir[23] = 1;
	mir[24] = 1;
	
	while(t--){
	  string s;
	  cin >> s;
	  int cnt = 0;
	  string ss = s;
	  reverse(ss.begin(), ss.end());
	  for(char c : s) cnt += mir[c-'A'];
	  if(cnt == s.size() && ss == s) cout << "yes" << endl;
	  else cout << "no" << endl;
	}
}
