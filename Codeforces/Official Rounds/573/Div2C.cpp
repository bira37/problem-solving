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

int page(int x, int k){
  return (x/k);
}

int32_t main(){
  DESYNC;
  int n,m,k;
  cin >> n >> m >> k;
  int v[m];
  for(int i=0; i<m; i++){
    cin >> v[i];
    v[i]--;
  }
  int st = 0;
  int tira = 0;
  int op = 0;
  while(st <= m-1){
    int l = st;
    int r = m-1;
    int ans = -1;
    //cout << "at " << st << endl;
    while(l <= r){
      int m = (l+r)>>1;
      //cout << "check " << m << endl;
      if(page(v[st] - tira, k) >= page(v[m] - tira, k)){
        ans = m;
        l = m+1;
       // cout << "ok" << endl;
      }
      else{
        r = m-1;
      //  cout << "no" << endl;
      }
    }
    op++;
    tira += ans-st+1;
    st = ans+1;
  }
  cout << op << endl;  
}

