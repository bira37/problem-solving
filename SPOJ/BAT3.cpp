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
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    k++;
    int lis[n+1];
    lis[0] = 0;
    vector<int> v(n+1);
    v[0] = INT_MAX;
    for(int i=0; i<n; i++){
      cin >> v[i+1];
    }
    int mx = 0;
    for(int i=1; i<=n; i++){
      lis[i] = 0;
      for(int j = 0; j < i; j++){
        if(v[j] > v[i] || (j == k && v[j] <= v[i])){
          lis[i] = max(lis[i], lis[j]+1);
        }
      }
      mx = max(mx, lis[i]);
    }
    cout << mx << endl;
  }
}


