#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n;
  cin >> n;
  int v[n];
  for(int i=0; i<n; i++) cin >> v[i];
  if(v[n-1] == 1){
    cout << "NO" << endl;
    return 0;
  }
  if(n == 1){
    if(v[0] == 1) cout << "NO" << endl;
    else cout << "YES" << endl << 0 << endl;
    return 0;
  }
  if(n == 2){
    if(v[n-2] == 1 && v[n-1] == 0) cout << "YES" << endl << "1->0" << endl;
    else cout << "NO" << endl;
    return 0;
  }
  if(v[n-2] == 1 && v[n-1] == 0){
    cout << "YES" << endl;
    cout << v[0];
    for(int i=1; i<n; i++) cout << "->" << v[i];
    cout << endl;
    return 0;
  }
  if(v[n-2] == 0 && v[n-1] == 0){
    int pos = -1;
    for(int i=n-3; i>=0; i--){
      if(v[i] == 0){
        pos = i;
        break;
      }
    }
    if(pos == -1){
      cout << "NO" << endl;
      return 0;
    }
    cout << "YES" << endl;
    if(pos == 0) cout << "(" << v[0];
    else cout << v[0];
    for(int i=1; i<n-2; i++){
      if(pos == i) cout << "->(" << v[i];
      else if(pos+1 == i) cout << "->(" << v[i];
      else cout << "->" << v[i];
    }
    if(pos+1 == n-2) cout << "->(" << v[n-2] << "))->" << v[n-1] << endl;
    else cout << "->" << v[n-2] << "))->" << v[n-1] << endl;
  }
}
