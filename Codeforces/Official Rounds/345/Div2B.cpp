#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v;
  set<int> s;
  int ans = 0;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    if(s.count(x)) v.push_back(x);
    else s.insert(x);
  }
  
  while(s.size() > 0){
    ans += s.size() -1;
    s.clear();
    vector<int> a;
    for(int x : v){
      if(s.count(x)) a.push_back(x);
      else s.insert(x);
    }
    v = a;
  }
  
  cout << ans << endl;
}