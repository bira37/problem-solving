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
 
int cnt = 0;
int fre[10];
 
void upd(int n) {
  int di;
  while(n) {
    di = n%10;
    if(fre[di] == 0) {
      cnt++;
    }
    fre[di]++;
    n/=10;
  }
}
 
int32_t main(){
  DESYNC;
  
  int n;
  while(cin >> n) {
    cnt = 0;
    memset(fre, 0, sizeof fre);
    
    int aux = n;
    int ans=  0;
    while(cnt < 10) {
      upd(aux);
      ans++;
      aux += n;
    }
    cout << ans << endl;
  }
}
 
