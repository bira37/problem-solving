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
  
  int n, k, r;
  cin >> n >> k >> r;
  int a[n+1];
  memset(a, 0, sizeof a);
  int id;
  
  for(int i = 1; i <= k; i++) {
    cin >> id;
    a[id] = 1;
  }
  int pre[n+1];
  memset(pre, 0, sizeof pre);
  for(int i = 1; i <= n; i++) {
    if(i) pre[i] = pre[i-1];
    pre[i] += a[i];
  }
  int acum = 0;
  for(int i = r; i <= n; i++) {
    pre[i] += acum;
    if(pre[i]-pre[i-r] < 1) {
      a[i-1] = 1;
      pre[i-1]++;
      pre[i]++;
      acum++;
      a[i] = 1;
      pre[i]++;
      acum++; 
    } else if(pre[i]-pre[i-r] < 2) {
      if(a[i] == 1) {
        //cout << i << endl;
        a[i-1] = 1;
        pre[i-1]++;
        pre[i]++;
        acum++;
      }else {
        //cout << i << endl;
        a[i] = 1;
        pre[i]++;
        acum++;
      }
    }
  }
  cout << acum << endl;
}
 
