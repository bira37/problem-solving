#include <bits/stdc++.h>

using namespace std;

int main(){
  int x,y;
  cin >> y >> x;
  x--;
  if(x < 0){
    cout << "No" << endl;
    return 0;
  }
  if(x == 0 && y > 0){
    cout << "No" << endl;
    return 0;
  }
  y -= x;
  if(y%2 || y < 0) cout << "No" << endl;
  else cout << "Yes" << endl;
}