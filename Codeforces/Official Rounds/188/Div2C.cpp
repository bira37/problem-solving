#include <bits/stdc++.h>

using namespace std;

#define int long long
int32_t main() {
  int a,b,m;
  cin >> a >> b >> m;
  if(max(a,b) >= m){
    cout << 0 << endl;
    return 0;
  }
  if(max(a,b) <= 0){
    cout << -1 << endl;
    return 0;
  }
  int ans = 0;
  if(min(a,b) < 0){
    int x = -min(a,b);
    int y = max(a,b);
    ans += (x + (y-1))/(y);
    x = -x;
    x += y*ans;
    a = x;
    b = y;
  }
  while(max(a,b) < m){
    if(a > b) swap(a,b);
    a = a+b;
    ans++;
  }
  cout << ans << endl;
}