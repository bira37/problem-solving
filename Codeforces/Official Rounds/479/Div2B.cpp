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
  string s;
  int n; cin>> n;
  cin >> s;
  map<string, int> cnt;
  for(int i=0; i<s.size()-1; i++){
    string t;
    t += s[i];
    t += s[i+1];
    cnt[t]++;
  }
  int best = 0;
  string ans = "";
  for(auto t : cnt){
    if(t.second > best){
      ans = t.first;
      best = t.second;
    }
  }
  cout << ans <<  endl;
}