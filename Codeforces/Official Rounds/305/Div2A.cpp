#include <bits/stdc++.h>
 
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
	string s;
	cin >> s;
	vector<string> v;
	int k;
	cin >> k;
	int n = s.size();
	if(n%k){
	  cout << "NO" << endl;
	  return 0;
	}
	for(int i=0; i<n; i+=n/k){
	  string t;
	  for(int j=i; j<i+n/k; j++) t += s[j];
	  string tt = t;
	  reverse(tt.begin(), tt.end());
	  if(t != tt){
	    cout << "NO" << endl;
	    return 0;
	  }
	}
	cout << "YES" << endl;
}
