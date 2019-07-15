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

int go(int n, int k){
  int lst = ((n-1)/k) * k + 1;
  int ans = ((1 + lst)*((lst-1)/k + 1))/2;
  return ans;
}
  

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  set<int> v;
  for(int i=2; i<=sqrt(n); i++){
    if(n%i == 0){
      v.insert(go(n,i));
      v.insert(go(n, n/i));
    }
  }
  v.insert(1);
  v.insert((n*(n+1))/2);
  for(int x : v) cout << x << " ";
  cout << endl;
}

