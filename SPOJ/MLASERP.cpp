#include <bits/stdc++.h>
#define pb push_back
#define INF 1e9
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {-1, 0, 1, 0};
int dir[] = {0, 1, 2, 3};

int n,m;
char mat[112][112];
int dist[112][112][4];
bool valid(int x, int y){
  return x >= 0 && y >= 0 && x < n && y < m && mat[x][y] != '*';
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> m >> n;
  int s1 = -1,s2 = -1;
  int e1, e2;
  int ans = INF;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> mat[i][j];
      if(mat[i][j] == 'C'){
          s1 = i, s2 = j;
      }
      dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = dist[i][j][3] = INF;
    }
  }
  mat[s1][s2] = '.';
  queue< tuple<int,int,int,int> > q;
  dist[s1][s2][0] = dist[s1][s2][1] = dist[s1][s2][2] = dist[s1][s2][3] = 0;
  q.push(make_tuple(s1,s2,0, 0));
  q.push(make_tuple(s1,s2,1, 0));
  q.push(make_tuple(s1,s2,2, 0));
  q.push(make_tuple(s1,s2,3, 0));
  while(!q.empty()){
    int x,y, didi, d;
    tie(x,y,didi,d) = q.front();
    q.pop();
    if(mat[x][y] == 'C'){
      ans = min(ans, d);
    }
    if(dist[x][y][didi] < d) continue;
    for(int k = 0; k<4; k++){
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(dist[nx][ny][dir[k]] <= d + (didi != dir[k])) continue;
      if(!valid(nx,ny)) continue;
      dist[nx][ny][dir[k]] = d + (didi != dir[k]);
      q.push(make_tuple(nx,ny, dir[k], d + (didi != dir[k])));
    }
  }
  cout << ans << endl;
}
  
  
