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
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
struct range{
  int first, second, id;
  range() {}
  range(int first , int second, int id) : first(first), second(second), id(id) {}
  bool operator<(const range & b) const{
    return second < b.second || (second == b.second && first > b.first) || (first == b.first && second == b.second && id < b.id);
  }
};
 
int32_t main(){
	DESYNC;
	int n,m;
	cin >> n >> m;
	ii last;
	cin >> last.ff >> last.ss;
	vector< range > v;
	for(int i=0; i<n-1; i++){
	  ii cur;
	  cin >> cur.ff >> cur.ss;
	  v.pb(range(cur.ff - last.ss, cur.ss - last.ff, i));
	  last = cur;
	}
	sort(v.begin(), v.end());
	set< ii > s;
	for(int i=0; i<m; i++){
	  int x;
	  cin >> x;
	  s.insert(ii(x, i+1));
	}
	int ans[n-1];
	for(int i=0; i<n-1; i++){
	  range cur = v[i];
	  //cout << "at range " << cur.ff << " " << cur.ss << "  " << cur.id << endl;
	  auto it = s.lower_bound(ii(cur.ff,-1));
	  if(it == s.end()){
	    cout << "No" << endl;
	    return 0;
	  }
	  ii bridge = *it;
	  if(bridge.ff > cur.ss){
	    cout << "No" << endl;
	    return 0;
	  }
	  ans[cur.id] = bridge.ss;
	  s.erase(it);
	}
	cout << "Yes" << endl;
	for(int i=0; i<n-1; i++){
	  if(i) cout << " ";
	  cout << ans[i];
	}
	cout << endl;
}
 
