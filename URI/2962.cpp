#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
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
  if(a == 0) return b;
  else return gcd(b%a, a);
}

struct circle{
  int x,y,r;
  circle() {}
  circle(int x, int y, int r) : x(x), y(y), r(r){}
  bool intersect (circle c){
    if((c.r + r)*(c.r + r) >= (x-c.x)*(x-c.x) + (y-c.y)*(y-c.y)) return true;
    else return false;
  }
};

int uf[11234];

void init(int n){
  for(int i=0; i<=n; i++) uf[i] = i;
}

int find(int u){
  if(uf[u] == u) return u;
  else return uf[u] = find(uf[u]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);
  if(a == b) return;
  if(rand()%2) swap(a,b);
  uf[b] = a;
}

int32_t main(){
  DESYNC;
  int n,m,k;
  cin >> n >> m >> k;
  init(k+3); //0 is left - k+1 is right - k+2 is up - k+3 is down 
  circle v[n];
  for(int i=1; i<=k; i++){
    int x,y,r;
    cin >> x >> y >> r;
    //cout << i << endl;
    if(x-r <= 0){
      //cout << "connect left" << endl;
      merge(i, 0);
    }
    if(x+r >= n) {
      merge(i, k+1);
      //cout << "connect right" << endl;
    }
    if(y-r <= 0) {
      //cout << "connect up" << endl;
      merge(i, k+2);
    }
    if(y+r >= m) {
      //cout << "connect down" << endl;
      merge(i, k+3);
    }
    v[i] = circle(x,y,r);
  }

  for(int i=1; i<=k; i++){
    for(int j=i+1; j<=k; j++){
      if(v[i].intersect(v[j])) {
        //cout << "connect " << i << " " << j << endl;
        merge(i, j);
      }
    }
  }

  if(find(0) == find(k+1)) cout << "N" << endl;
  else if(find(0) == find(k+2)) cout << "N" << endl;
  else if(find(k+2) == find(k+3)) cout << "N" << endl;
  else if(find(k+1) == find(k+3)) cout << "N" << endl;
  else cout << "S" << endl;
}



