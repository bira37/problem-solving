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

int dist(int a, int b){
  return min(abs(b - a), 26 - abs(b - a));
}

int32_t main(){
  DESYNC;
  int n;
  string s;
  cin >> n >> s;
  int ans = INF;
  for(int i=0; i<=n-4; i++){
    int dst = 0;
    dst += dist('A' - 'A', s[i] - 'A');
    dst += dist('C' - 'A', s[i+1] - 'A');
    dst += dist('T' - 'A', s[i+2] - 'A');
    dst += dist('G' - 'A', s[i+3] - 'A');
    ans = min(ans, dst);
  }
  cout << ans << endl;
}

