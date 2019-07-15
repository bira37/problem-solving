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
  int n,k;
  cin >> n >> k;
  int sum = 0;
  int v[n];
  for(int i=0; i<n; i++){
    cin >> v[i];
    sum += v[i];
  }
  if(sum%k){
    cout << "No" << endl;
    return 0;
  }
  
  int cur = 0;
  vector<int> ans;
  int cnt = 0;
  for(int i=0; i<n; i++){
    cnt++;
    cur += v[i];
    if(cur > sum/k){
      cout << "No" << endl;
      return 0;
    }
    if(cur == sum/k){
      ans.pb(cnt);
      cnt = 0;
      cur =0;
    }
  }
  cout << "Yes" << endl;
  for(int x : ans) cout << x << " ";
  cout << endl;
}

