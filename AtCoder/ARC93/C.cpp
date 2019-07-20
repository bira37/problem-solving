#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int v[n];
  int tot = 0;
  for(int i=0; i<n; i++) cin >> v[i];
  tot += abs(v[0]);
  for(int i=1; i<n; i++) tot += abs(v[i] - v[i-1]);
  tot += abs(v[n-1]);
  
  //for zero
  cout << tot - abs(v[0]) - abs(v[0] - v[1]) + abs(v[1]) << endl;
  
  for(int i=1; i<n-1; i++){
    cout << tot - abs(v[i] - v[i-1]) - abs(v[i] - v[i+1]) + abs(v[i-1] - v[i+1]) << endl;
  }
  
  //for last
  cout << tot - abs(v[n-1] - v[n-2]) - abs(v[n-1]) + abs(v[n-2]) << endl;
}
