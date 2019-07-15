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
	int x,y;
	cin >> x >> y;
	if(x == y) cout << '=';
	else if(x == 1 && y != 1) cout << '<';
	else if(x != 1 && y == 1) cout << '>';
	else {
	  bool swaped = false;
	  if(x > y) {swap(x,y); swaped = true;}
	  if(x >= 3){
	    if(swaped) cout << '<';
	    else cout << '>';
	  }
	  else if(x == 2){
	    if(y == 3){
	      if(swaped) cout << '>';
	      else cout << '<';
	    }
	    else if(y == 4) cout << '=';
	    else {
	      if(swaped) cout << '<';
	      else cout << '>';
	    }
	  }
	}
	cout << endl;
}

