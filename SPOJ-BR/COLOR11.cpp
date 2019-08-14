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

int dx[] = {0,1,0,-1,1,1,-1,-1};
int dy[] = {1,0,-1,0,1,-1,-1,1};
int tot = 0;
int n,m,k,x,y;
bool mat[500][500];

bool valid(int a, int b){
  return a >= 0 && b >= 0 && a < n && b < m && mat[a][b];
}

void go(int a, int b){
  tot++;
  mat[a][b] = false;
  for(int k=0;  k<8; k++){
    int nx = a + dx[k];
    int ny = b + dy[k];
    if(!valid(nx, ny)) continue;
    go(nx, ny);
  }
}
  
int32_t main(){
  DESYNC;
  cin >> n >> m >> x >> y >> k;
  for(int i=0; i<n; i++){
    for(int j=0; j<m;j++) mat[i][j] = true;
  }
  while(k--){
    int a,b;
    cin>> a >> b;
    a--,b--;
    mat[a][b] = false;
  }
  x--,y--;
  go(x,y);
  cout << tot << endl;
}


