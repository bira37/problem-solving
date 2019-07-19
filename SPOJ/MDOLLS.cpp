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
  vector< ii > pointer;
  int sz;
  LIS() {}

  LIS(int n){
    seq.resize(n+1);
    pointer.resize(n);
  }
  
  void calculate(vector<int> & v){
    int n = v.size();
    vector<int> aux(n+1);
    for(int i=1; i<=n; i++){
      seq[i] = INT_MAX;
      aux[i] = -1;
    }
    seq[0] = INT_MIN;
    aux[0] = -1;
    for(int i=0; i<n; i++){
      int index = upper_bound(seq.begin(), seq.end(), v[i]) - seq.begin();
      index--;
      if(seq[index+1] > v[i]){
        seq[index+1] = min(seq[index+1], v[i]);
        aux[index+1] = i;
      }
      pointer[i] = ii(index+1, aux[index]);  
    }
    for(int i=n; i>=0; i--){
      if(seq[i] != INT_MAX){
        sz = i;
        break;
      }
    }
  }
};

bool cmp(const ii & a, const ii & b){
  return a.ff < b.ff || (a.ff == b.ff && a.ss > b.ss);
}

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector< ii > v(n);
    for(int i=0; i<n; i++) cin >> v[i].ff >> v[i].ss;
    sort(v.begin(), v.end(), cmp);
    vector<int> a;
    for(int i=n-1; i>=0; i--) a.pb(v[i].ss);
    LIS lis(n);
    lis.calculate(a);
    cout << lis.sz << endl; 
  }
}


