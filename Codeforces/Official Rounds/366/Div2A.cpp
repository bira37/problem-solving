#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int n;
  cin >> n;
  
  for(int i=0; i<n; i++){
    if(i%2) cout << "I love";
    else cout << "I hate";
    if(i != n-1) cout << " that ";
  }
  
  cout << " it" << endl;
}
