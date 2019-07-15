#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int ans = 0;
  for(int i=1; i<=n; i++){
    for(int j = i; j <= n; j++){
      int x = (i^j);
      if(x <= n && x >= j && (i+j) > x) ans++;
    }
  }
  cout << ans << endl;
}