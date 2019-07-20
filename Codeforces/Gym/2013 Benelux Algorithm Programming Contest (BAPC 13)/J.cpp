#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_tuple
#define mt make_tuple
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e9
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
 
int n,m;
int d1[101][101], d2[101][101], d3[101][101];
char mat[101][101];
 
bool wall(int x, int y){
  return mat[x][y] == '*';
}
 
bool valid(int x, int y){
  return x >= 0 && y >= 0 && x < n && y < m;
}
 
bool cost(int x, int y){
  return mat[x][y] == '#';
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    cin >> n >> m;
    ii lad1, lad2;
    bool got1 = false;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin >> mat[i][j];
        d1[i][j] = d2[i][j] = d3[i][j] = INF;
        if(mat[i][j] == '$'){
          if(!got1){
            lad1 = ii(i,j);
            got1 = true;
          }
          else {
            lad2 = ii(i,j);
          }
        }
      }
    }
    //from the first one
    set< tuple<int,int,int> > s;
    s.insert(mt(cost(lad1.ff, lad1.ss), lad1.ff, lad1.ss));
    d1[lad1.ff][lad1.ss]= 0;
    while(!s.empty()){
      int dst, x, y;
      tie(dst, x, y) = *s.begin();
      s.erase(s.begin());
      if(d1[x][y] < dst) continue;
      for(int k=0; k<4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(wall(nx, ny) || !valid(nx,ny)) continue;
        if(dst + cost(nx, ny) < d1[nx][ny]){
          d1[nx][ny] =dst + cost(nx, ny);
          s.insert(mt(d1[nx][ny], nx, ny));
        }
      }
    }
    //from the second one
    s.clear();
    s.insert(mt(cost(lad2.ff, lad2.ss), lad2.ff, lad2.ss));
    d2[lad2.ff][lad2.ss] = 0;
    while(!s.empty()){
      int dst, x, y;
      tie(dst, x, y) = *s.begin();
      s.erase(s.begin());
      if(d2[x][y] < dst) continue;
      for(int k=0; k<4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(wall(nx, ny) || !valid(nx,ny)) continue;
        if(dst + cost(nx, ny) < d2[nx][ny]){
          d2[nx][ny] =dst + cost(nx, ny);
          s.insert(mt(d2[nx][ny], nx, ny));
        }
      }
    }
    //from the borders
    s.clear();
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(wall(i,j)) continue;
        if(i == 0 || j == 0 || i == n-1 || j == m-1){
          s.insert(mt(cost(i,j), i, j));
          d3[i][j] = cost(i,j);
        }
      }
    }
    while(!s.empty()){
      int dst, x, y;
      tie(dst, x, y) = *s.begin();
      s.erase(s.begin());
      if(d3[x][y] < dst) continue;
      for(int k=0; k<4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(wall(nx, ny) || !valid(nx,ny)) continue;
        if(dst + cost(nx, ny) < d3[nx][ny]){
          d3[nx][ny] =dst + cost(nx, ny);
          s.insert(mt(d3[nx][ny], nx, ny));
        }
      }
    }
    int ans = INF;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        //cout << i << " " << j << " " << d1[i][j] << " " << d2[i][j] << " " << d3[i][j] << " " << d1[i][j] + d2[i][j] + d3[i][j] << endl;
        ans = min(ans, d1[i][j] + d2[i][j] + d3[i][j] - 2*(mat[i][j] == '#'));
      }
    }
    if(ans < n*m+100) cout << ans << endl;
    else if(ans >= n*m+100){
      int ans1 = INF;
      int ans2 = INF;
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          if(wall(i,j)) continue;
          if(i == 0 || j == 0 || i == n-1 || j == m-1){
            ans1 = min(ans1, d1[i][j]);
            ans2 = min(ans2, d2[i][j]);
          }
        }
      }
      cout << ans1 + ans2 << endl;
    }
  }
}
 
