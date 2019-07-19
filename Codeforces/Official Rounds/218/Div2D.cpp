#include <bits/stdc++.h>
 
#define int long long
#define double long double
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
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int32_t main(){
	DESYNC;
	int n;
	set< ii > s;
	cin >> n;
	int v[n+1];
	for(int i=1; i<=n; i++){
	  int x;
	  cin >> x;
	  v[i] = x;
	  s.insert(ii(i, x));
	}
	int q;
	cin >> q;
	while(q--){
	  int op;
	  cin >> op;
	  if(op == 2){
	    int id;
	    cin >> id;
	    auto it = s.lower_bound(ii(id, -1));
	    if(it == s.end() || it->first != id) cout << v[id] << endl;
	    else cout << v[id] - it->second << endl;
	  }
	  else {
	    int id, x;
	    cin >> id >> x;
	    while(true){
	      auto it = s.lower_bound(ii(id, -1));
	      if(it == s.end()) break;
	      ii p = *it;
	      s.erase(it);
	      int tira = min(x, p.second);
	      p.second -= tira;
	      x -= tira;
	      if(p.second > 0){
	        s.insert(p);
	      }
	      if(x == 0) break;
	    }
	  }
	}
}
 
