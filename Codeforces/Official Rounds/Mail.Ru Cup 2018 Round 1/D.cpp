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

int n,k;
int v[212345];

int neg(int x){
  int ans = 0;
  for(int i=0; i<k; i++){
    if((1LL<<i) & x) {}
    else ans |= (1LL<<i);
  }
  return ans;
}

int32_t main(){
  DESYNC;
  cin >> n >> k;
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  int ans = 0;
  map<int,int> m;
  m[0] = 1;
  int xx = 0;
  for(int i=0; i<n; i++){
    int a = m[xx^v[i]];
    int b = m[xx^neg(v[i])];
    if(a < b){
      ans += a;
      xx = xx^v[i];
    }
    else {
      ans += b;
      xx = xx^neg(v[i]);
    }
    m[xx]++;
  }
  cout << (n*(n+1))/2 - ans << endl; 
}

