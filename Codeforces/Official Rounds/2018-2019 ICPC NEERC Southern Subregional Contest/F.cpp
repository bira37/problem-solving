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

int32_t main(){
  DESYNC;
 
 
  int n;
  cin >> n;
  
  vector< pair<int, int> > pe;
  int sta, inf;
  int ans = 0;
  int c10 = 0, c01 = 0, c00 = 0;
  for(int i = 0; i < n; i++) {
    cin >> sta >> inf;
    if(sta == 11) {
      c00++;
      ans += inf;
    } else {
      if(sta == 10) c01++;
      if(sta == 1) c10++;
      pe.pb(make_pair(inf, sta));
    }
  }
  sort(pe.begin(), pe.end(), greater< pair<int,int> >());
  
  //cout << ans << endl;
  
  for(int i = 0; i < pe.size(); i++) {
    int sta = pe[i].second;
    int inf = pe[i].first;
    if(sta == 10) {
      if(c10) {
        ans += inf;
        c10--;
      } else if(c00) {
        ans += inf;
        c00--;
      }
    } else if(sta == 1) {
      if(c01) {
        ans += inf;
        c01--;
      } else if(c00) {
        ans += inf;
        c00--;
      }
    } else {
      if(c00) {
        ans += inf;
        c00--;
      }
    }
    //cout << ans << endl;
  }
  
  
  cout << ans << endl;
}

