#include <bits/stdc++.h>

using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int ans = 0;
  
  while(true){
    
    if(a > b) swap(a,b);
    if(a == 0 || b <= 1) break;
    a += 1;
    a = min(a, 100);
    b-=2;
    ans++;
    //cout << a << " " << b << endl;
  }
  
  cout << ans << endl;
}