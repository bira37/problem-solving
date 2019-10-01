#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n,k,r;
  cin >> n >> k >> r;
  int v[n];
  vector<int> cnt(n, 0);
  for(int i=0; i<k; i++){
    int x;
    cin >> x;
    cnt[x-1]++;
  }
  
  //for(int i=0; i<n; i++) cout << cnt[i] << " ";
  //cout << endl;
  
  int cur = 0;
  int ans = 0;
  for(int i=0; i<r; i++){
    cur += cnt[i];
  }
  
  if(cur < 2){
    if(cur == 0){
      cur++;
      cnt[r-1]++;
      ans++;
    }
    if(cur == 1){
      cur++;
      if(cnt[r-1] > 0) cnt[r-2]++;
      else cnt[r-1]++;
      ans++;
    }
  }
  
  for(int i=1; i<n && i+r-1 < n; i++){
    cur -= cnt[i-1];
    cur += cnt[i+r-1];
    
    if(cur < 2){
      if(cur == 0){
        cur++;
        cnt[i+r-1-1]++;
        ans++;
      }
      if(cur == 1){
        cur++;
        if(cnt[i+r-1] > 0) cnt[i+r-2]++;
        else cnt[i+r-1]++;
        ans++;
      }
    }
  }
  
  //for(int i=0; i<n; i++) cout << cnt[i] << " ";
 // cout << endl;
  cout << ans << endl;
}
