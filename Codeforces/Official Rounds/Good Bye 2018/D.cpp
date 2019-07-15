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
#define M 998244353
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

int exp(int a, int k){
  if(k == 1) return a;
  if(k == 0) return 1;
  int aux = exp(a, k/2);
  aux = mod(aux*aux, M);
  if(k%2) aux = mod(aux*a, M);
  return aux;
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int fat = 1;
  int ans = n;
  for(int i=1; i<=n; i++){
    ans = mod(ans*i, M);
    fat = mod(fat*i, M);
  }
  int acc = 1;
  for(int i=1; i<=n-1; i++){
    acc = mod(acc*i, M);
    int inv = exp(acc, M-2);
    ans = mod(ans - mod(inv*fat, M), M);
  }
  cout << ans << endl;
}

