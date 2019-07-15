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
  int n,k;
  cin >> n >> k;
  map<int,int> cnt;
  set<int> v;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    cnt[x]++;
    v.insert(x);
  }
  if(k == 0 && *v.begin() != 1){
    cout << 1 << endl;
    return 0;
  }
  if(k == 0 && *v.begin() == 1){
    cout << -1 << endl;
    return 0;
  }
  int less = 0;
  for(int x : v){
    less += cnt[x];
    if(less == k){
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}