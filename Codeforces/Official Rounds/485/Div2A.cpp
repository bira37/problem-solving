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
	set<string> ss;
	ss.insert("Power");
	ss.insert("Time");
	ss.insert("Space");
	ss.insert("Soul");
	ss.insert("Reality");
	ss.insert("Mind");
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
	  string s;
	  cin >> s;
	  if(s == "red") s = "Reality";
	  else if(s == "purple") s = "Power";
	  else if(s == "blue") s = "Space";
	  else if(s == "green") s = "Time";
	  else if(s == "yellow") s = "Mind";
	  else s = "Soul";
	  ss.erase(s);
	}
	
	cout << ss.size() << endl;
	for(string k : ss) cout << k << endl;
}

