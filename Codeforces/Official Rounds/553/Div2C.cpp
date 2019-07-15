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

int sum_odd(int x){
  return mod(mod(x, M)*mod(x, M), M);
}

int sum_even(int x){
  return mod(mod(x, M)*mod(x+1, M), M);
}

int solve(int x){
  int cur = 1;
  int odd = 0;
  int even = 0;
  bool f = 1;
  while(x > 0){
    int write = min(x, cur);
    if(f) odd += write;
    else even += write;
    f = !f;
    cur <<= 1;
    x -= write;
  }
  return mod(sum_odd(odd) + sum_even(even), M);
}

int32_t main(){
  DESYNC;
  int l, r;
  cin >> l >> r;
  cout << mod(solve(r) - solve(l-1), M) << endl;
}

