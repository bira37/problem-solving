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

int32_t main(){
  DESYNC;
  int q;
  cin >> q;
loop:  while(q--){
    int n;
    cin >> n;
    int ans[n];
    tuple<int,int,int> v[n];
    for(int i=0; i<n; i++){
      int l,r,id;
      cin >> l >> r;
      id = i;
      v[i] = tie(l,r,id);
    }
    sort(v, v+n);
    int g1 = -1;
    int g2 = -1;
    for(auto p : v){
      int l,r,id;
      tie(l,r,id) = p;
      if(l <= g1){
        if(l <= g2){
          cout << -1 << endl;
          goto loop;
        }
        g1 = max(g1, r);
        ans[id] = 1;
      }
      else if(l <= g2){
        if(l <= g1){
          cout << -1 << endl;
          goto loop;
        }
        g2 = max(g2, r);
        ans[id] = 2;
      }
      else {
        if(g1 == -1){
          g1 = max(g1, r);
          ans[id] = 1;
        }
        else {
          g2 = max(g2, r);
          ans[id] = 2;
        }
      }
    }
    if(g1 == -1 || g2 == -1){
      cout << -1 << endl;
      goto loop;
    }
    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << endl;
  }
      
}

