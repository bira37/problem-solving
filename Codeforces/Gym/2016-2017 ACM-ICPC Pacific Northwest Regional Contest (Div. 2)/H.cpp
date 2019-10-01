#include <bits/stdc++.h>
 
using namespace std;
int n,m;
char tab[150][150];
int vis[150][150];
int isl = 0;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool ok(int i,int j){
    return (i>=0 && i<n && j>=0 && j<m && tab[i][j]!='W');
}
void dfs(int i,int j){
    vis[i][j] = 1;
    for(int k=0;k<4;k++){
        int ni = i + dx[k], nj = j + dy[k];
        if(ok(ni,nj) && !vis[ni][nj]){
            dfs(ni,nj);
        }
    }
}
int main(){
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin >> tab[i][j];
        vis[i][j] = 0;
      }
   }
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(tab[i][j] == 'L' && !vis[i][j]){
              isl++;
              dfs(i,j);
           }
      }
   }
   cout << isl << endl;
}
