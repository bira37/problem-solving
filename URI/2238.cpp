#include <bits/stdc++.h>

using namespace std;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int mx = 2000000000;
  for(int i = 1; i<=sqrt(c); i++){
    if(i%a == 0 && i%b != 0 && c%i == 0 && d%i != 0){
      mx = min(mx, i);
    }
    if(c%i == 0){
      if((c/i)%a == 0 && (c/i)%b != 0 && c%(c/i) == 0 && d%(c/i) != 0){
        mx = min(mx, c/i);
      }
    }
  }
  if(mx == 2000000000) mx = -1;
  cout << mx << endl;
}
