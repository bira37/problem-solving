#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int instant = 1;
    int ans[n];
    for(int i=0; i<n; i++){
      int l, r;
      cin >> l >> r;
      if(instant < l) instant = l;
      if(instant <= r){
        ans[i] = instant;
        instant++;
      }
      else ans[i] = 0;
    }
    for(int i=0; i<n; i++){
      if(i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
}