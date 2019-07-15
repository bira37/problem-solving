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

int a[312345], b[312345];

int32_t main(){
  int n;
  int m;
  scanf("%I64d", &n); 
  for(int i=n-1; i>=0; i--){
    scanf("%I64d", &a[i]); 
  }
  scanf("%I64d", &m); 
  for(int i=m-1; i>=0; i--){
    scanf("%I64d", &b[i]); 
  }
  int sa = 0, sb = 0;
  int pa = n-1, pb = m-1;
  int ans = 0;
  while(pa >= 0 || pb >= 0){
    if(sa < sb && pa >= 0){
      sa += a[pa];
      pa--;
    }
    else if(sa < sb && pa < 0) break;
    else if(sb < sa && pb >= 0){
      sb += b[pb];
      pb--;
    }
    else if(sb < sa && pb < 0) break;
    if(sa == sb && sa > 0){
      ans++;
      sa = 0;
      sb = 0;
    }
    else if(sa == sb){
      if(pa >= 0){
        sa += a[pa];
        pa--;
      }
      else if(pb >= 0){
        sb += b[pb];
        pb--;
      }
      else break;
    }
  }
  if(sa == 0 && sb == 0) printf("%I64d\n", ans);
  else puts("-1");
}

