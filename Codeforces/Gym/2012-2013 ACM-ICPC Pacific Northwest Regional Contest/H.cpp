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
 
int bit[112345];
 
void init(int n){
  for(int i=0; i<=n; i++) bit[i] = 0;
}
 
void update(int idx, int val, int n){
  for(int i=idx; i<=n; i += i&-i){
    bit[i] += val;
  }
}
 
int prefix_query(int idx){
  int ans = 0;
  for(int i=idx; i>0; i-= i&-i){
    ans += bit[i];
  }
  return ans;
}
 
 
 
int32_t main(){
  DESYNC;
  int n;
  while(cin >> n, n != 0){
    map<string, int> m;
    init(n);
    for(int i=1; i<=n; i++){
      string s;
      cin >> s;
      m[s] = i;
    }
    vector<int> v(n);
    for(int i=0; i<n; i++){
      string s;
      cin >> s;
      v[i] = m[s];
    }
    int ans = 0;
    reverse(v.begin(), v.end());
    for(int i=0; i<n; i++){
      ans += prefix_query(v[i]);
      update(v[i], 1, n);
    }
    cout << ans << endl;
  }    
}
 
