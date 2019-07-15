#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main(){
  int a,b,c,n;
  cin >> a >> b >> c >> n;
  a -= c;
  b -= c;
  if(a < 0 || b < 0){
    cout << -1 << endl;
    return 0;
  }
  
  n -= (a+b+c);
  if(n <= 0){
    cout << -1 << endl;
    return 0;
  }
  
  cout << n << endl;
}