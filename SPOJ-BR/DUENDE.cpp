#include <bits/stdc++.h>
#define pb push_back
#define INF 1e9
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {-1, 0, 1, 0};
int n,m;
int mat[112][112];
int dist[112][112];
bool valid(int x, int y){
  return x >= 0 && y >= 0 && x < n && y < m && mat[x][y] != 2;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  int x,y;
  int ans = INF;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> mat[i][j];
      if(mat[i][j] == 3){
        x = i, y = j;
      }
      dist[i][j] = INF;
    }
  }
  queue< tuple<int,int,int> > q;
  dist[x][y] = 0;
  q.push(make_tuple(x,y,0));
  while(!q.empty()){
    int x,y,d;
    tie(x,y,d) = q.front();
    q.pop();
    if(mat[x][y] == 0) ans = min(ans, d);
    if(dist[x][y] < d) continue;
    for(int k = 0; k<4; k++){
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(dist[nx][ny] <= d+1) continue;
      if(!valid(nx,ny)) continue;
      dist[nx][ny] = d+1;
      q.push(make_tuple(nx,ny, d+1));
    }
  }
  cout << ans << endl;
}
  
  
