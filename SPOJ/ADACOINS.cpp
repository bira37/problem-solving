#include <bits/stdc++.h>

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

int dp[100001];

int32_t main(){
  int n, q;
  scanf("%d%d", &n, &q);
  bitset<100001> bs, aux;
  bs.set(0);
  for(int i=0; i<n; i++){
    int x;
    scanf("%d", &x);
    aux |= bs;
    aux <<= x;
    bs |= aux;
  }
  dp[0] = 0;
  for(int i=1; i<=100000; i++) dp[i] = dp[i-1] + bs[i];
  while(q--){
    int l,r;
    scanf("%d%d", &l, &r);
    printf("%d\n", dp[r] - dp[l-1]);
  }
}


