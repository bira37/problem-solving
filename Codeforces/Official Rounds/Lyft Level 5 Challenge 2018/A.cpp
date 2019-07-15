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
int n, ax,ay,bx,by,cx,cy;
bool vis[1123][1123] = {0};
bool mat[1123][1123];
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

bool valid(ii cur){
  return cur.ff > 0 && cur.ss > 0 && cur.ff <= n && cur.ss <= n && mat[cur.ff][cur.ss];
}

int32_t main(){
  DESYNC;
  cin >> n;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      mat[i][j] = true;
      vis[i][j] = false;
    }
  }
  
  for(int i = 1; i<=n; i++){
    mat[ax][i] = mat[i][ay] = false;
  }
  
  for(int i= ax, j = ay; i > 0 && j > 0 && i <= n && j <= n; i += 1, j += 1) mat[i][j] = false;
  for(int i= ax, j = ay; i > 0 && j > 0 && i <= n && j <= n; i += -1, j += 1) mat[i][j] = false;
  for(int i= ax, j = ay; i > 0 && j > 0 && i <= n && j <= n; i += 1, j += -1) mat[i][j] = false;
  for(int i= ax, j = ay; i > 0 && j > 0 && i <= n && j <= n; i += -1, j += -1) mat[i][j] = false;
  
  queue< ii > q;
  vis[bx][by] = true;
  q.push(ii(bx,by));
  
  while(!q.empty()){
    ii cur = q.front();
    q.pop();
    for(int k = 0; k<8; k++){
      int nx = cur.ff + dx[k];
      int ny = cur.ss + dy[k];
      if(!valid(ii(nx,ny)) || vis[nx][ny]) continue;
      vis[nx][ny] = true;
      q.push(ii(nx,ny));
    }
  }
  if(vis[cx][cy]) cout << "YES" << endl;
  else cout << "NO" << endl;    
}

