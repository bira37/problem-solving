#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  int contavaga = 0;
  char mat[n][m];
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> mat[i][j];
      if(mat[i][j] == '.') contavaga++;
    }
  }
  if(k == 1){
    cout << contavaga << endl;
    return 0;
  }
  int ways = 0;
  for(int i=0; i<n; i++){
    int cnt = 0;
    for(int j=0; j<m; j++){
      if(mat[i][j] == '.') cnt++;
      else {
        ways += max(0, (cnt-k+1));
        cnt = 0;
      }
    }
    ways += max(0, (cnt-k+1));
  }
  
  for(int j=0; j<m; j++){
    int cnt = 0;
    for(int i=0; i<n; i++){
      if(mat[i][j] == '.') cnt++;
      else {
        ways += max(0, (cnt-k +1));
        cnt = 0;
      }
    }
    ways += max(0, (cnt-k +1));
  }
  
  cout << ways << endl;
}