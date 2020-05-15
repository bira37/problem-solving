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

int exp(int a, int k){
  if(k == 0) return 1;
  if(k == 1) return a;
  int aux = exp(a, k/2);
  aux = mod(aux*aux, M);
  if(k % 2) aux = mod(aux*a, M);
  return aux;
}

int fat[(1<<16)+10];
int inv[(1<<16)+10];

int A(int n, int k){
  if(n < 0 || k < 0) return 0;
  if(n-k < 0) return 0;
  return mod(fat[n]*inv[n - k], M);
}

int32_t main(){
  DESYNC;
  fat[0] = 1;
  inv[0] = 1;
  for(int i=1; i<=(1<<16); i++){
    fat[i] = mod(i*fat[i-1], M);
    inv[i] = exp(fat[i], M-2);
  }
  int n,k;
  cin >> n >> k;
  k--;
  int juca;
  cin >> juca;
  int p = 0;
  vector<int> v;
  for(int i=1; i<(1<<n); i++){
    int x;
    cin >> x;
    v.pb(x);
    if(x < juca) p++;
  }
  sort(v.begin(), v.end());
  int ans = 0;
  int x = (1<<n) - (1<<(k+1));
  int pos = (1<<n)/(1<<(k+1));
  if(k == n){
    //number of ways of choosing 2^k-1 losers for juca
    int cur = A(p, (1<<k)-1);
    //number of ways of positioning juca into these guys
    cur = mod(cur*(1<<k), M);
    cout << cur << endl;
    return 0;
  }
  for(int i=0; i < v.size(); i++){
    int g = i;
    if(v[i] < juca) continue;
    g++;
    //number of ways of choosing 2^k-1 losers for juca
    int cur = A(p, (1<<k)-1);
    //number of ways of positioning juca into these guys
    cur = mod(cur*(1<<k), M);
    //number of ways of choosing 2^k-1 losers for the guy who beats juca
    cur = mod(cur*A(g - (1<<k), (1<<k)-1), M);
    //number of ways of positioning the man into these guys
    cur = mod(cur*(1<<k), M);
    //number of ways of permutate remaining guys
    cur = mod(cur*fat[x], M);
    //number of ways of positioning our tree
    cur = mod(cur*pos, M);
    //multiply by two (we can swap juca's tree and the guy's tree)
    cur = mod(cur*2LL, M);
    //sum up to the answer
    ans = mod(ans + cur, M);
  }
  cout << ans << endl;   
}


