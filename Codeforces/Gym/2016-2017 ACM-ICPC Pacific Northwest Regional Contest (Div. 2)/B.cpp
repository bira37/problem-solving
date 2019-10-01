#include <bits/stdc++.h>
 
using namespace std;
 
int a[14],b[14];
int n,m;
 
int s1 = 0, s2 = 0;
 
vector<int> s;
set<int> ans;
 
void go(int i){
  if(i == m){
    if(s1 == s2) s.push_back(s1+s2);
    return;
  }
  
  //pick one
  s1 += b[i];
  go(i+1);
  s1 -= b[i];
  
  //pick two
  s2 += b[i];
  go(i+1);
  s2 -= b[i];
  
  //pick neither
  go(i+1);
}
 
int main(){
  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<m; i++) cin >> b[i];
  
  go(0);
  
  for(int i=0; i<n; i++){
    for(int x : s) ans.insert(x + a[i]);
  }
  
  for(int x : ans) cout << x << endl;
   
}
