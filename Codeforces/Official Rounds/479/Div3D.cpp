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
  int n;
  cin >> n;
  int v[n];
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  
  for(int i=0; i<n; i++){
    //start with i;
    
    vector<int> ans;
    ans.pb(v[i]);
    set<int> s;
    for(int j=0; j<n; j++){
      if(i == j) continue;
      s.insert(v[j]);
    }
    while(!s.empty()){
      if(s.count(2LL*ans.back())){
        s.erase(2LL*ans.back());
        ans.pb(2LL*ans.back());
      }
      else if(ans.back()%3 == 0 && s.count(ans.back()/3LL)){
        s.erase(ans.back()/3LL);
        ans.pb(ans.back()/3LL);
      }
      else break;
    }
    
    if(s.empty()){
      for(int x : ans) cout << x << " ";
      cout << endl;
      return 0;
    }
  }
  
  for(int i=0; i<n; i++){
    //start with i;
    
    vector<int> ans;
    ans.pb(v[i]);
    set<int> s;
    for(int j=0; j<n; j++){
      if(i == j) continue;
      s.insert(v[j]);
    }
    while(!s.empty()){
      if(ans.back()%3 == 0 && s.count(ans.back()/3LL)){
        s.erase(ans.back()/3LL);
        ans.pb(ans.back()/3LL);
      }
      else if(s.count(2LL*ans.back())){
        s.erase(2LL*ans.back());
        ans.pb(2LL*ans.back());
      }
      else break;
    }
    
    if(s.empty()){
      for(int x : ans) cout << x << " ";
      cout << endl;
      return 0;
    }
  }
  
}