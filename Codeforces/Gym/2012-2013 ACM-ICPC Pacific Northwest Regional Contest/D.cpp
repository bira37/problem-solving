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
#define EPS 1e-12
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
 
struct point{
  double x,y;
  double ang;
  point() {}
  point(double x, double y, double ang) : x(x), y(y), ang(ang) {}
  bool operator<(const point & b){
    return ang < b.ang;
  }
};
 
vector<point> v;
int cnt = 0;
int want;
 
double calculate_angle(double x, double y, point p){
  double ang = atan2((double)(p.y - y), (double)(p.x - x));
  return ang > 0 ? ang : (2.*PI + ang);
}
 
bool check(point v1, point v2){
  if(abs(v1.x*v2.y - v1.y*v2.x) <= EPS) return cnt < want;
  else return (v1.x*v2.y - v1.y*v2.x) > 0;
}
 
int32_t main(){
  DESYNC;
  int k,n,m;
loop:  while(cin >> k >> n >> m, k + n + m != 0){
    v.clear();
    want = k/2;
    point c(n/2., m/2., 0);
    for(int i=0; i<k; i++){
      int x,y;
      cin >> x >> y;
      double ang = calculate_angle((double)n/2., (double)m/2., point(x,y, 0));
      v.pb(point(x,y, ang));
    }
    sort(v.begin(), v.end());
    
    int j = 1;
    cnt = 1;
    point vec(v[0].x - c.x, v[0].y - c.y, 0);  
    while(j < k){
      point vec2(v[j].x - c.x, v[j].y - c.y, 0);
      if(check(vec, vec2)) cnt++, j++;
      else break;
    }
    
    if(cnt == want){
      for(int i=0; i<j; i++){
        cout << (int)(v[i].x) << " " << (int)v[i].y << endl;
      }
      goto loop;
    }
    
    if(cnt-1 == want){
      for(int i=1; i<j; i++){
        cout << (int)(v[i].x) << " " << (int)v[i].y << endl;
      }
      goto loop;
    }
    
    for(int i=1; i<k; i++){
      cnt--;
      if(j == i){
        j++;
        cnt++;
      }
      j %= k;
      point vec(v[i].x - c.x, v[i].y - c.y, 0);  
      while(j != i){
        point vec2(v[j].x - c.x, v[j].y - c.y, 0);
        if(check(vec, vec2)){
          cnt++, j++;
          j %= k;
        }
        else break;
      }
      
      if(cnt == want){
        int it = i;
        while(it != j){
          cout << (int)(v[it].x) << " " << (int)v[it].y << endl;
          it++;
          it %= k;
        }
        goto loop;
      }
      
      if(cnt-1 == want){
        int it = i+1;
        it %= k;
        while(it != j){
          cout << (int)(v[it].x) << " " << (int)v[it].y << endl;
          it++;
          it %= k;
        }
        goto loop;
      }
    }
    cout << "nao achou" << endl;
  }
}
