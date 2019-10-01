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
  string s;
  cin >> s;
  int q;
  cin >> q;
  int n = s.size();
  set<int> pos[26];
  for(int i=0; i<n; i++){
    pos[s[i]-'a'].insert(i);
  }
  while(q--){
    int t;
    cin >> t;
    if(t == 1){
      int x;
      char c;
      cin >> x >> c;
      x--;
      pos[s[x]-'a'].erase(x);
      pos[c-'a'].insert(x);
      s[x] = c;
    }
    else {
      int l,r;
      cin >> l >> r;
      l--,r--;
      int ans = 0;
      for(int i=0; i<26; i++){
        auto it = pos[i].lower_bound(l);
        if(it != pos[i].end() and *it <= r) ans++;
      }
      cout << ans << endl;
    }
  }
}
