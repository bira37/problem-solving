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
 
int32_t main(){
	DESYNC;
	string a,b,c;
	cin >> a >> b >> c;
	int ha[26], hb[26], hc[26];
	for(int i=0; i<26; i++){
	  ha[i] = hb[i] = hc[i] = 0;
	}
	for(char c : a) ha[c-'a']++;
	for(char c : b) hb[c-'a']++;
	for(char k : c) hc[k-'a']++;
	
	int eqb = 112345;
	for(int i=0; i<26; i++){
	  if(hb[i] > 0) eqb = min(eqb, ha[i]/hb[i]);
	}
	int best = -1;
	int tot = 0;
	for(int j=0; j<=eqb; j++){
	  int h[26];
	  for(int i=0; i<26; i++) h[i] = ha[i];
	  for(int i=0; i<26; i++) h[i] -= j*hb[i];
	  int eqc = 112345;
	  for(int i=0; i<26; i++){
	    if(hc[i] > 0) eqc = min(eqc, h[i]/hc[i]);
	  }
	  if(tot <= eqc + j){
	    best = j;
	    tot = eqc+j;
	  }
	}
	//cout << best << " " << tot << endl;
	eqb = best;
	string ans;
	while(eqb > 0){
	  ans += b;
	  eqb--;
	  for(int i=0; i<26; i++) ha[i] -= hb[i];
	}
	int eqc = 112345;
  for(int i=0; i<26; i++){
    if(hc[i] > 0) eqc = min(eqc, ha[i]/hc[i]);
  }
  while(eqc>0){
	  ans += c;
	  eqc--;
	  for(int i=0; i<26; i++) ha[i] -= hc[i];
	}
	for(int i=0; i<26; i++){
	  while(ha[i] > 0){
	    ans += 'a'+i;
	    ha[i]--;
	  }
	}
	cout << ans << endl;
}
