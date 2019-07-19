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
	string s;
	cin >> s;
	bool ok1 = false, ok2 = false;
	set<int> ab;
	set<int> ba;
	for(int i=0; i<s.size()-1; i++){
	  if(s[i] == 'A' && s[i+1] == 'B'){
	    ab.insert(i);
	  }
	}
	for(int i=0; i<s.size()-1; i++){
	  if(s[i] == 'B' && s[i+1] == 'A'){
	    ba.insert(i);
	  }
	}
	for(int x : ab){
	  if(ba.upper_bound(x+1) != ba.end()){
	    cout << "YES" << endl;
	    return 0;
	  }
	}
	for(int x : ba){
	  if(ab.upper_bound(x+1) != ab.end()){
	    cout << "YES" << endl;
	    return 0;
	  }
	}
	cout << "NO" << endl;
}
 
