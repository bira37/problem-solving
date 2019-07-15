#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    int v[n];
    for(int i=0; i<n; i++) v[i] = 99999999;
    for(int i=0; i<k; i++){
      int start;
      cin >> start;
      start--;
      v[start] = min(v[start], 1);
      int conta = 2;
      for(int j = start-1; j>=0;j--, conta++) v[j] = min(v[j], conta);
      conta = 2;
      for(int j = start+1; j<n;j++, conta++) v[j] = min(v[j], conta); 
    }
    int ans = 0;
    for(int i=0; i<n; i++) ans = max(ans, v[i]);
    cout << ans << endl;
  }
}