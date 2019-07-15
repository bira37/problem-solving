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

int go(vector<int> odd, vector<int> even, int s, int f){
    if(f == 1) swap(odd, even);
    if(odd.size() == 0) return s;
    s -= odd.back();
    odd.pop_back();
    while(true){
        if(even.size() == 0) break;
        s -= even.back();
        even.pop_back();
        if(odd.size() == 0) break;
        s -= odd.back();
        odd.pop_back();
    }
    return s;
}

int32_t main(){
  DESYNC;
  int n;
  vector<int> odd, even;
  int s = 0;
  cin >> n;
  for(int i=0; i<n; i++){
      int x;
      cin >> x;
      s +=x;
      if(x%2) odd.pb(x);
      else even.pb(x);
  }
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());
  cout << min(go(odd, even, s, 0), go(odd, even, s, 1)) << endl;
}