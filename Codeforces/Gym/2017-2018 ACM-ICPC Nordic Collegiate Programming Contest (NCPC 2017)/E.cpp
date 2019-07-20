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
 
int h, w;
int arr[501][501];
bool vis[501][501]={};
int _floor_arr[501][501]={};
 
struct quad{
  int _floor, value, i, j;
  
  quad(int _floor, int value, int i, int j) :  
  _floor(_floor), value(value), i(i), j(j)
  {}
 
  bool operator<(const quad& b) const {
    return !(tie(_floor, value, i, j) < tie(b._floor, b.value, b.i, b.j));
  }
};
 
 
void dij(int i, int j, int f){
  priority_queue<quad> pq;
  pq.push(quad(f, arr[i][j], i, j));
  vis[i][j]=true;
  _floor_arr[i][j] = arr[i][j];
  while(!pq.empty()){
    auto item=pq.top();
    pq.pop();
    int f=item._floor, x=item.i, y=item.j;
    for(int i=-1; i<=1; ++i){
      for(int j=-1; j<=1; ++j){
        if(!i && !j)
          continue;
        if(x+i <0 || x+i>=h)
          continue;
        if(y+j <0 || y+j>=w)
          continue;
        if(vis[x+i][y+j])
          continue;
        vis[x+i][y+j]=true;
        _floor_arr[x+i][y+j]=max(arr[x+i][y+j], _floor_arr[x][y]);
        pq.push(quad(_floor_arr[x+i][y+j], arr[x+i][y+j], x+i, y+j));
      }
    }
  }
}
 
 
int32_t main(){
  DESYNC;
  cin >> h >> w;
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      cin >> arr[i][j];
      if(arr[i][j]>=0)
        vis[i][j]=true;
    }
  }
  int i, j;
  cin >> i >> j;
  dij(i-1, j-1, arr[i-1][j-1]);
  int sum=0;
  for(int i=0; i<h; ++i)
    for(int j=0; j<w; ++j)
      sum+=_floor_arr[i][j];
  cout << -sum << endl;
}
 
