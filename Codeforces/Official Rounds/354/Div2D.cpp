#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define mt make_tuple
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
char rot(char c){
  if(c == '+') return '+';
  if(c == '-') return '|';
  if(c == '|') return '-';
  if(c == '^') return '>';
  if(c == '>') return 'v';
  if(c == 'v') return '<';
  if(c == '<') return '^';
  if(c == '*') return '*';
  if(c == 'L') return 'U';
  if(c == 'U') return 'R';
  if(c == 'R') return 'D';
  if(c == 'D') return 'L';
}
 
map<char, vector<ii> > moves;
 
vector<ii> dir;
int U = 0;
int D = 1;
int L = 2;
int R = 3;
int n,m;
char mat[1123][1123][4];
int d[1123][1123][4];
 
void load_moves(){
  moves['+'].pb(dir[U]);
  moves['|'].pb(dir[U]);
  moves['^'].pb(dir[U]);
  moves['L'].pb(dir[U]);
  moves['R'].pb(dir[U]);
  moves['D'].pb(dir[U]);
  
  moves['+'].pb(dir[D]);
  moves['|'].pb(dir[D]);
  moves['v'].pb(dir[D]);
  moves['L'].pb(dir[D]);
  moves['R'].pb(dir[D]);
  moves['U'].pb(dir[D]);
  
  moves['+'].pb(dir[L]);
  moves['-'].pb(dir[L]);
  moves['<'].pb(dir[L]);
  moves['R'].pb(dir[L]);
  moves['U'].pb(dir[L]);
  moves['D'].pb(dir[L]);
  
  moves['+'].pb(dir[R]);
  moves['-'].pb(dir[R]);
  moves['>'].pb(dir[R]);
  moves['L'].pb(dir[R]);
  moves['U'].pb(dir[R]);
  moves['D'].pb(dir[R]);
  
}
 
bool valid(int x, int y, int l){
  return x >= 0 && x < n && y >= 0 && y < m && mat[x][y][l] != '*';
}
 
int32_t main(){
  DESYNC;
  cin >> n >> m;
  dir.pb(ii(-1,0));
  dir.pb(ii(1,0));
  dir.pb(ii(0,-1));
  dir.pb(ii(0,1));
  
  load_moves();
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> mat[i][j][0];
      d[i][j][0] = INF;
      for(int k = 1; k<4; k++){
        mat[i][j][k] = rot(mat[i][j][k-1]);
        d[i][j][k] = INF;
      }
    }
  }
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  sx--,sy--,tx--,ty--;
  queue< tuple<int,int,int,int> > q;
  q.push(mt(sx,sy,0, 0));
  d[sx][sy][0] = 0;
  while(!q.empty()){
    int x,y,l,dst;
    tie(x,y,l,dst) = q.front();
    q.pop();
    if(d[x][y][l] < dst) continue;
    //cout << x << " " << y << " " << l << " " << dst << " " << mat[x][y][l] << endl;
    if(d[x][y][(l+1)%4] > dst+1){
      d[x][y][(l+1)%4] = dst+1;
      q.push(mt(x,y,(l+1)%4, dst+1));
    }
    for(ii move : moves[mat[x][y][l]]){
      //cout << x+move.ff << " " << y+move.ss << " " << l << mat[x + move.ff][y+move.ss][l] << endl;
      if(valid(x + move.ff, y + move.ss, l) && d[x+move.ff][y+move.ss][l] > dst+1){
        int nx = x +move.ff;
        int ny = y+move.ss;
        set<ii> s;
        for(ii move_ret : moves[mat[nx][ny][l]]){
          s.insert(ii(nx+move_ret.ff, ny+move_ret.ss));
        }
        if(!s.count(ii(x,y))) continue;
        d[x+move.ff][y+move.ss][l] = dst+1;
        q.push(mt(x+move.ff, y+move.ss, l, d[x+move.ff][y+move.ss][l]));
      }
    }
  }
  
  int ans = INF;
  for(int i=0; i<4; i++) ans = min(ans, d[tx][ty][i]);
  cout << (ans >= INF ? -1 : ans) << endl;
}
