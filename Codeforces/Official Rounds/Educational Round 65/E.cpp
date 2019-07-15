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
#define INF 1e9
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

int32_t main(){
  DESYNC;
  int n,x;
  cin >> n >> x;
  int mx[x+1], mn[x+2];
  bool pre[x+1], suf[x+2];
  pre[0] = true;
  map<int, vector<int>> pos;
  for(int i=0;  i<n; i++){
     int x;
     cin >> x;
     pos[x].pb(i);
  }
  //calculate pre
  int lst = -1;
  pre[0] = true;
  mx[0] = -1;
  for(int i=1; i<=x; i++){
    if(!pre[i-1]) pre[i] = false;
    else{
      if(!pos.count(i)){
        pre[i] = true;
        mx[i] = mx[i-1]; 
      }
      else if(pos[i].front() > lst){
        pre[i] = true;
        lst = pos[i].back();
        mx[i] = lst;
      }
      else pre[i] = false;
    }
  }
  //calculate suf
  lst = n+1;
  mn[x+1] = n+1;
  suf[x+1] = true;
  for(int i=x; i>=1; i--){
    if(!suf[i+1]) suf[i] = false;
    else {
      if(!pos.count(i)){
        suf[i] = true;
        mn[i] = mn[i+1];
      }
      else if(pos[i].back() < lst){
        suf[i] = true;
        lst = pos[i].front();
        mn[i] = lst;
      }
      else suf[i] = false;
    }
  }
  int ans = 0;
  lst = -1;
  for(int l = 1; l <= x; l++){
    if(!pre[l-1]) continue;
    int lo = l, hi = x;
    int r = l;
    while(lo <= hi){
      int md = (lo+hi)>>1;
      if(!suf[md]){
        lo = md + 1;
        r = md;
      }
      else if(suf[md] && mn[md] < lst){
        lo = md+1;
        r = md;
      }
      else if(suf[md] && lst < mn[md]){
        hi = md-1;
      }
    }
    //cout << l << " " << r << endl;
    if(r != -1) ans += (x - r + 1);
    lst = mx[l];
  }
  cout << ans << endl;
}

