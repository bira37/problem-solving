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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  int ans = 0;  
  int sum = 0;
  for(int i=0; i<n; i++){
    sum += v[i];
    int nxt = (i+1)%n;
    ans += v[i]*v[nxt];
  }
  int caps = 0;
  set<int> cap;
  for(int i=0; i<k; i++){
    int x;
    cin >> x;
    x--;
    int prev = x-1;
    if(prev == -1) prev = n-1;
    int nxt = x+1;
    if(nxt == n) nxt = 0;
    if(cap.count(prev)) prev = 0;
    else prev = v[prev];
    if(cap.count(nxt)) nxt = 0;
    else nxt = v[nxt];
    caps += v[x]*(sum - v[x] - prev - nxt);
    sum -= v[x];
    cap.insert(x);
  }
  cout << ans + caps << endl;
}
 
