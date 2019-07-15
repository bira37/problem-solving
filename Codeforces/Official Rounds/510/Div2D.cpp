#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;


inline int mod(int n){ return (n%1000000007); }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}

typedef tree<
ii, 
null_type,
less< ii >, 
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int key = 0;

int gen(){
  return key++;
}

int32_t main(){
	DESYNC;
	int n, k;
	cin >> n >> k;
	ordered_set s;
	s.insert(ii(k, gen()));
	int ans = 0;
	int sum = 0;
	for(int i=0; i<n; i++){
	  int x;
	  cin >> x;
	  sum += x;
	  auto it = s.upper_bound(ii(sum, 112345));
	  if(it == s.end()){
	    s.insert(ii(sum+k,gen()));
	    continue;
	  }
	  else ans += s.size() - s.order_of_key(*it);
	  s.insert(ii(sum + k,gen()));
	}
	cout << ans << endl;
}

