#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main(){

  int n;
  cin >> n;
  int v[n];
  for(int i=0; i<n; i++) cin >> v[i];
  sort(v, v+n);
  
  int ans = 0;
  int sum = 0;
  for(int i=0; i<n; i++){
    sum += v[i];
  }
  if(round((double)sum/(double)n) >= 5){
    cout << 0 << endl;
    return 0;
  }
  
  for(int i=0; i<n; i++){
    ans++;
    v[i] = 5;
    int sum = 0;
    for(int j =0 ; j<n; j++){
      sum += v[j];
    }
    if(round((double)sum/(double)n) >=  5){
      cout << ans << endl;
      return 0;
    }
  }
}