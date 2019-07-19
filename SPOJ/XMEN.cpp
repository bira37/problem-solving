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
/* Use upper_bound to swap to longest non decreasing subsequence */

struct LIS{

  vector<int> seq;
  int sz;
  LIS() {}

  LIS(int n){
    seq.resize(n+1);
  }
  
  void calculate(vector<int> & v){
    int n = v.size();
    for(int i=1; i<=n; i++) seq[i] = INT_MAX;
    seq[0] = INT_MIN;
    for(int i=0; i<n; i++){
      int index = lower_bound(seq.begin(), seq.end(), v[i]) - seq.begin();
      index--;
      seq[index+1] = min(seq[index+1], v[i]);
    }
    for(int i=n; i>=0; i--){
      if(seq[i] != INT_MAX){
        sz = i;
        break;
      }
    }
  }
};

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    map<int,int> m;
    for(int i=0; i<n; i++){
      int x;
      cin >> x;
      m[x] = i;
    }
    vector<int> v(n);
    for(int i=0; i<n; i++){
      cin >> v[i];
      v[i] = m[v[i]];
    }
    LIS lis(n);
    lis.calculate(v);
    cout << lis.sz << endl;
  }
}


