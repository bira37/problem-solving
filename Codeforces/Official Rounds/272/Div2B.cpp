#include <bits/stdc++.h>

#define int long long
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
  int x = 0;
  int y = 0;
  int cnt = 0;
  string s;
  cin >> s;
  for(char c : s){
    if(c == '+') x++;
    else x--;
  }
  cin >> s;
  for(char c : s){
    if(c == '+') y++;
    else if(c == '-') y--;
    else cnt++;
  }
  int need = abs(x-y);
  if(cnt == 0){
    if(need == 0) cout << "1.00000000000000" << endl;
    else cout << "0.0000000000000000" << endl;
    return 0;
  }
  double ans = 0;
  int den = (1<<cnt);
  int fatcnt = 1;
  for(int i=1; i<=cnt; i++) fatcnt *= i;
  for(int i=0; i<=cnt/2; i++){
    int j = cnt-i;
    if(abs(i-j) == need){
      int fatj = 1;
      int fatcntj = 1;
      for(int k=1; k<=cnt-j; k++) fatcntj *= k;
      for(int k = 1; k<= j; k++) fatj *= k;
      int num = fatcnt/fatj;
      num /= fatcntj;
      ans += double(num)/double(den);
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}

