#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  multiset<int, greater<int>> big;
  multiset<int> small;
  int cur = 0;
  int ans = 0;
  for(int i=1; i<=n; i++){
    int x;
    cin >> x;
    int tm = m - x;
    while(cur > tm && big.size() > 0){
      cur -= *big.begin();
      small.insert(*big.begin());
      big.erase(big.begin());
      ans++;
    }
    while(small.size() > 0 && *small.begin() + cur <= tm){
      big.insert(*small.begin());
      cur += *small.begin();
      small.erase(small.begin());
      ans--;
    }
    
    while(big.size() > 0 && small.size() > 0 && *big.begin() > *small.begin()){
      cur -= *big.begin();
      small.insert(*big.begin());
      big.erase(big.begin());
      ans++;
      
      while(small.size() > 0 && *small.begin() + cur <= tm){
        big.insert(*small.begin());
        cur += *small.begin();
        small.erase(small.begin());
        ans--;
      }
      
    }
    
    cout << ans << " ";
    big.insert(x);
    cur += x;
  }
  cout << endl;  
}

