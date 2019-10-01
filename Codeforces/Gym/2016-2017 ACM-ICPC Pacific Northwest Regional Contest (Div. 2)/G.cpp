#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n,m;
  cin >> n >> m;
  char c[n][m];
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> c[i][j];
    }
  }
  
  for(int i=n-1; i>=0; i--){
    for(int j=m-1; j>=0; j--){
      if(c[i][j] == 'o'){
        int pos = i;
        c[i][j] = '.';
        while(pos < n and c[pos][j] == '.') pos++;
        pos--;
        c[pos][j] = 'o';
      }
    }
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout << c[i][j];
    }
    cout << endl;
  }
  
}
