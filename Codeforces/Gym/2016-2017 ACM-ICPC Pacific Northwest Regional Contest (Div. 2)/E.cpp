#include <bits/stdc++.h>
 
using namespace std;
#define int long long
main(){
  int n,k;
  cin >> n >> k;
  vector<int> v(n);
  for(int &x : v) cin >> x;
  priority_queue<int,vector<int>, greater<int>> pq;
  int tmp = 0, ans = 0;
  for(int i=0;;){
    if(pq.size() < k && i < n){
      pq.push(v[i]);
      i++;
    }
    else{
      if(pq.empty()){
        break;
      }
      else{
         int ch = pq.top();
         pq.pop();
         tmp += ch;
         ans += tmp;
      }
    }
  } 
  cout << ans << endl;
}
