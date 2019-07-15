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
const double PI = acos(-1);

using namespace std;

inline int mod(int n){ return (n%1000000007); }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}


char mat[3123][3123];
int n,m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int vis[3123][3123];
int dp[3123][3123];
char nxt[255];

bool valid(int a, int b){
  return a >= 0 && a < n && b >= 0 && b < m;
}

int mx = 0;

void dfs(int x, int y){
  vis[x][y] = 1;
  if(mx == INF) return;
  dp[x][y] = 1;
  int best = 0;
  for(int i=0; i<4; i++){
    int xx = dx[i] + x;
    int yy = dy[i] + y;
    if(!valid(xx, yy)) continue;
    if(nxt[mat[x][y]] != mat[xx][yy]) continue;
    if(vis[xx][yy] == 1) mx = INF;
    if(mx == INF) return;
    if(vis[xx][yy] == 0) dfs(xx,yy);
    best = max(best, dp[xx][yy]);
    if(mx == INF) return;
  }
  dp[x][y] += best;
  vis[x][y] = 2;
}
int32_t main(){
  DESYNC;
  nxt['D'] = 'I';
  nxt['I'] = 'M';
  nxt['M'] = 'A';
  nxt['A'] = 'D';
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      vis[i][j] = 0;
      dp[i][j] = 0;
      cin >> mat[i][j];
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(mx != INF && mat[i][j] == 'D' && vis[i][j] == 0){
        dfs(i,j);
        mx = max(mx, dp[i][j]/4);
      }
    }
  }
  if(mx == 0) cout << "Poor Dima!" << endl;
  else if(mx == INF) cout << "Poor Inna!" << endl;
  else cout << mx << endl;
}