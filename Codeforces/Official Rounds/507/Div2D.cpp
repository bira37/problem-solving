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

int32_t main(){
  int n,k;
  srand(time(NULL));
  cin >> n >> k;
  int l = 1, r = n;
  while(true){
    if(r-l+1 <= 100){
      int chuta = l + rand()%(r-l+1);
      cout << chuta << " " << chuta << endl;
      cout.flush();
      string ans;
      cin >> ans;
      if(ans == "Yes") return 0;
      l-= k;
      r += k;
      l = max(1LL, l);
      r = min(n, r);
    }
    int m = (l+r)>>1;
    cout << l << " " << m << endl;
    cout.flush();
    string ans;
    cin >>ans;
    if(ans == "Yes" && l == m) return 0;
    if(ans == "Yes"){
      r = m;
    }
    else l = m;
    l-= k;
    r += k;
    l = max(1LL, l);
    r = min(n, r);
  } 
}

