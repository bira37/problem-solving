#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  int test = 0;
  while(t--){
    cout << "Case #" << ++test << ": ";
    int c;
    cin >> c;
    int v[c];
    for(int i=0; i<c; i++) cin >> v[i];
    int p = 0;
    map< pair<int,int>, int > m;
    bool ok = true;
    for(int i=0; i<c; i++){
      while(p < c && v[p] <= 0) p++;
      if(p < c && v[p] > 0){
        int curr = i;
        int desc = 0;
        while(curr != p){
          if(p < curr){
            if(curr == 0 || curr == c-1) ok = false;
            m[make_pair(desc, curr)] = -1;
            curr--;
            desc++;
          }
          else if(p > curr){
            if(curr == 0 || curr ==  c-1) ok = false;
            m[make_pair(desc, curr)] = 1;
            curr++;
            desc++;
          }
        }
        v[p]--;
      }    
    }
    while(p < c && v[p] <= 0) p++;
    if(p != c || !ok) cout << "IMPOSSIBLE" << endl;
    else {
      int max_r = 1;
      for(auto x : m){
        max_r = max(max_r, x.first.first+2);
      }
      
      char mat[max_r][c];
      for(int i=0; i<max_r; i++){
        for(int j = 0; j<c; j++){
          mat[i][j] = '.';
        }
      }
      
      for(auto x : m){
        if(x.second == 1) mat[x.first.first][x.first.second] = '\\';
        else mat[x.first.first][x.first.second] = '/';
      }
      
      cout << max_r << endl;
      for(int i=0; i<max_r; i++){
        for(int j = 0; j<c; j++){
          cout << mat[i][j];
        }
        cout <<endl;
      }
    }
  }
}
