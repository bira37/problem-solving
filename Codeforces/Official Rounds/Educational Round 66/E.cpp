#include <bits/stdc++.h>

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

int lift[22][512345];

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  vector< ii > segs;
  set<int, greater<int> > rs;
  for(int i=0; i<n; i++){
    int l,r;
    cin >> l >> r;
    segs.pb(ii(l,r));
  }
  sort(segs.begin(), segs.end());
  reverse(segs.begin(), segs.end());
  memset(lift, -1, sizeof lift);
  for(int i=0; i<512345; i++){
    while(segs.size() > 0 && segs.back().ff <= i){
      rs.insert(segs.back().ss);
      segs.pop_back();
    }
    if(rs.size() > 0 && *rs.begin() >= i) lift[0][i] = *rs.begin();
    else lift[0][i] = -1;
    //cout << "lift[0][" << i << "] = " << lift[0][i] << endl;
  }
  for(int i=1; i<22; i++){
    for(int j=0; j<512345; j++){
      if(lift[i-1][j] == -1) lift[i][j] = -1;
      else lift[i][j] = lift[i-1][lift[i-1][j]];
    }
  }
  while(m--){
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for(int i=21; i>=0; i--){
      //cout << "try to go from " << l << " to " << lift[i][l] << endl;
      if(lift[i][l] != -1 && lift[i][l] < r){
        //cout << "got it " << endl;
        l = lift[i][l];
        ans += (1<<i);
      }
    }
    if(lift[0][l] != -1 && lift[0][l] >= r) ans++;
    else ans = -1;
    cout << ans << endl;
  }       
}

