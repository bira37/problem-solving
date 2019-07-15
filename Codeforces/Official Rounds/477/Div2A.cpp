#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define endl '\n'
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;

inline int mod(int n){ return (n%1000000007); } 

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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, s;
	cin >> n >> s;
	int v[n];
	for(int i=0; i<n; i++){
	  int h,m;
	  cin >> h >> m;
	  v[i] = 60*h + m;
  }
  int curr = 0;
  if(curr + s < v[0]){
    int h = curr/60;
    int m = curr%60;
    cout << h << " " << m << endl;
    return 0;
  }
  for(int i=0; i<n-1; i++){
    int curr = v[i] + s + 1;
    if(curr + s < v[i+1]){
      int h = curr/60;
      int m = curr%60;
      cout << h << " " << m << endl;
      return 0;
    }
  }
  curr = v[n-1]+s+1;
  int h = curr/60;
  int m = curr%60;
  cout << h << " " << m << endl;
}