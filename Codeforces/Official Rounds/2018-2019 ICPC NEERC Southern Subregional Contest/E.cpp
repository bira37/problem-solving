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

int n, m, t;
int v[212345];

bool check(int thres){
  int cur = 0;
  int cnt = 0;
  int sum = 0;
  for(int i=0; i<n; i++){
    if(v[i] <= thres){
      if(cur + v[i] > t) return false;
      else {
        cnt++;
        cur += v[i];
        sum += v[i];
      }
    }
    if(cnt == m){
      cur += sum;
      sum = 0;
      cnt = 0;
    }
  }
  return true;
}

int construct(int thres){
  int cur = 0;
  int cnt = 0;
  int sum = 0;
  int qtd= 0;
  for(int i=0; i<n; i++){
    if(v[i] <= thres){
      if(cur + v[i] > t) return qtd;
      else {
        cnt++;
        qtd++;
        cur += v[i];
        sum += v[i];
      }
    }
    if(cnt == m){
      cur += sum;
      sum = 0;
      cnt = 0;
    }
  }
  return qtd;
}
      
int32_t main(){
  DESYNC;
  int test;
  cin >> test;
  while(test--){
    cin >> n >> m >> t;
    for(int i=0; i<n; i++) cin >> v[i];
    
    int l = 1, r = t;
    int ans = 0;
    while(l <= r){
      int m = (l+r)>>1;
      if(check(m)){
        ans = m;
        l = m+1;
      }
      else r = m-1;
    }
    int ret1 = construct(ans);
    int ret2 = construct(ans+1);
    
    if(ret1 < ret2) cout << ret2 << " " << ans+1 << endl;
    else cout << ret1 << " " << ans << endl;
  }
}

