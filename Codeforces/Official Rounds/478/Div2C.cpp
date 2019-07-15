#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define M 1000000007
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second
#define int long long

using namespace std;
using namespace __gnu_pbds;

//////////////////////////////////////////////STL - Ordered Set////////////////////////////////////////////
typedef tree<
int, //change for pair<int,int> to use like multiset
null_type,
less<int>, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int differ = 0;
//////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////

int32_t main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,q;
	cin >> n >> q;
	int curr = 0;
	int resta = 0;
	int v[n];
	int p[n+1];
	p[0] = 0;
	for(int i=0; i<n; i++){
	  cin >> v[i];
	  p[i+1] = v[i] + p[i];
	}
	
	while(q--){
	  int x;
	  cin >> x;
	  if(x < resta){
	  	resta -= x;
	  	//cout << "curr " << curr << endl;
	    //cout << "resta " << resta << endl;
	    if(n - curr == 0) cout << n << endl;
	    else cout << n - curr << endl;
	  	continue;
	  }
	  if(resta > 0){
	    x -= resta;
	    resta = 0;
	    curr++;
	  }
	  int l = curr, r = n;
	  int ans = curr;
	  while(l <= r){
	    int m = (l+r)/2;
	    if(p[m] - p[curr] <= x){
	      ans = m;
	      l = m+1;
	    }
	    else r = m-1;
	  }
	  x -= p[ans] - p[curr];
	  curr = ans;
	  if(curr < n) resta = p[ans+1] - p[ans] - x;
	  else resta = 0;
	  //cout << "curr " << curr << endl;
	  //cout << "resta " << resta << endl; 
	  if(n - curr == 0) cout << n << endl;
	  else cout << n - curr << endl;
	  curr %= n;
	}
}
