#include <bits/stdc++.h>
#define ii pair<int,int>
#define w first
#define h second
#define int long long
using namespace std;
 
 
int32_t main(){
  int n;
  cin >> n;
  int v[n];
  for(int i=0; i<n; i++) cin >> v[i];
  
  int l = 0;
  int r = 1e13;
  
  int ans = -1;
  
  while(l <= r){
    int m = (l+r)>>1;
    
    int cnt = 0;
    for(int i=0; i<n; i++) cnt += min(m, v[i]);
    
    if(cnt >= 2*m){
      ans = m;
      l = m+1;
    }
    else r = m-1;
  }
  
  cout << ans << endl;  
}
