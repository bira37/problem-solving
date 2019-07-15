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

int n,m,i,j,a,b;

int move(int xa, int ya){
  if(abs(xa-i)%a || abs(ya-j)%b){
    return INF;
  }
  int dx = abs(xa-i)/a;
  int dy = abs(ya-j)/b;
  if(dx == dy){
    return dx;
  }
  else if(abs(dx-dy)%2 == 0){
    if(dx == 0 && i + a > n && i-a < 1) return INF;
    else if(dy == 0 && j + b > m && j-b < 1) return INF;
    else return max(dx,dy);
  }
  return INF;
}

int32_t main(){
  DESYNC;
  cin >> n >> m >> i >> j >> a >> b;
  int ans = INF;
  ans = min(ans, move(1,1));
  ans = min(ans, move(n,m));
  ans = min(ans, move(1,m));
  ans = min(ans, move(n, 1));
  if(ans == INF) cout << "Poor Inna and pony!" << endl;
  else cout << ans << endl;
}