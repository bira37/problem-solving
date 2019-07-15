#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  map<int,int> m;
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int id, val;
    cin >> id >> val;
    m[id] = max(m[id], val);
  }
  cin >> n;
  for(int i=0; i<n; i++){
    int id, val;
    cin >> id >> val;
    m[id] = max(m[id], val);
  }
  int ans = 0;
  for(pair<int,int> x : m){
    ans += x.second;
  }
  cout << ans << endl;
}