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
 
int ans(int a, int b, int c){
  return a*a + b*b + c*c + 7*min(a, min(b, c));
}
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  while(n--){
    vector<int> v(3);
    int d;
    for(int i=0; i<3; ++i)
      cin >> v[i];
    cin >> d;
 
    int md = min(d, 100ll), m=0;
    d-=md;
    for(int i=0; i<=md; ++i){
      for(int j=0; j<=md-i; ++j){
        int a, b, c;
        a=v[0]+i;
        b=v[1]+j;
        c=v[2]+md-i-j;
        if(a==max(a, max(b, c)))
          a+=d;
        else if(b==max(a, max(b, c)))
          b+=d;
        else
          c+=d;
        m=max(m, ans(a, b, c));
      }
    }
    cout << m << endl;
  }
  return 0;
}
 
 
