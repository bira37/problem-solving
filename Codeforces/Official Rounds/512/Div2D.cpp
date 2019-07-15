#include <bits/stdc++.h>

#define int unsigned long long
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
  int n,m,k;
  cin >> n >> m >> k;
  if((n*m*2LL)%k != 0){
    cout << "NO" << endl;
    return 0;
  }
  if((2LL*n)%k == 0){
    cout << "YES" << endl;
    cout << "0 0" << endl;
    cout << (2LL*n)/k << " " << 0 << endl;
    cout << "0 " << m << endl;
    return 0;
  }
  if((2LL*m)%k == 0){
    cout << "YES" << endl;
    cout << "0 0" << endl;
    cout << 0 << " " << (2LL*m)/k << endl;
    cout << n << " 0" << endl;
    return 0;
  }
  if(k%2 == 0){
    int g = k/2;
    if(n%g == 0){
      cout << "YES" << endl;
      cout << "0 0" << endl;
      cout << n/g << " " << 0 << endl;
      cout << "0 " << m << endl;
      return 0;
    }
    if(m%g == 0){
      cout << "YES" << endl;
      cout << "0 0" << endl;
      cout << 0 << " " << m/g << endl;
      cout << n << " 0" << endl;
      return 0;
    }
  }
  if((2LL*n*m)%k == 0){
    int sz = (2LL*n*m)/k;
    for(int i=1, sqr = sqrt(sz); i<=sqr; i++){
      if(sz%i) continue;
      if(i <= n && sz/i <= m){
        cout << "YES" << endl;
        cout << "0 0" << endl;
        cout << "0 " << sz/i << endl;
        cout << i << " 0" << endl;
        return 0;
      }
      else if(i <= m && sz/i <= n){
        cout << "YES" << endl;
        cout << "0 0" << endl;
        cout << "0 " << i << endl;
        cout << sz/i << " 0" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  
}

