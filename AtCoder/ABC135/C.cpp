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
  int n;
  cin >> n;
  int v[n+1];
  int ans = 0;
  for(int i=0; i<n+1; i++){
    cin >> v[i];
  }
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    int tira = min(v[i], x);
    x -= tira;
    v[i] -= tira;
    ans += tira;
    tira = min(v[i+1], x);
    x -= tira;
    v[i+1] -= tira;
    ans += tira;
  }
  cout << ans << endl;
}


