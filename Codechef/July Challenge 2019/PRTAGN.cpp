#include <bits/stdc++.h>
using namespace std;

int count(int x){
  int ans = 0;
  for(int i=0; i<23; i++) if(x & (1<<i)) ans++;
  return ans;
}

void solve(){
  int q;
  cin >> q;
  int e = 0, o = 0;
  set<int> s;
  s.insert(0);
  while(q--){
    int x;
    cin >> x;
    set<int> ns;
    if(s.count(x)){
      cout << e << " " << o << endl;
      continue;
    }
    for(int y : s){
      if(s.count(x^y)) continue;
      ns.insert(x^y);
    }
    for(int x : ns){
      if(count(x) % 2) o++;
      else e++;
      s.insert(x);
    }
    cout << e << " " << o << endl;
  }
}
  
int32_t main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--) solve();
}
