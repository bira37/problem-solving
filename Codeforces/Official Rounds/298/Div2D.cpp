#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  set< pair<int,int>, greater< pair<int,int> > > s[3];
  
  vector<int> ans;
  bool ok = false;
  for(int i=0; i<n; i++){ 
    int x;
    cin >> x;
    s[x%3].insert(make_pair(x,i+1));
  }
  
  int cur = -1;
  while(ans.size() < n){
    int nxt = (cur+1)%3;
    auto it = s[nxt].lower_bound(make_pair(cur+1, INT_MAX));
    if(it == s[nxt].end()){
      cout << "Impossible" << '\n';
      return 0;
    }
    ans.push_back(it->second);
    cur = it->first;
    s[nxt].erase(it);
  }
  
  cout << "Possible\n";
  for(int x : ans) cout << x << " ";
  cout << '\n';
  
}