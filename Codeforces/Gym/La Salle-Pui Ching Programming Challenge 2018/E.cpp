#include <bits/stdc++.h>
 
#define int long long
#define ff first
#define ss second
#define endl '\n'
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define EPS 1e-9
#define INF (int)1e18
#define ROOT 1
 
using namespace std;
 
inline int mod(int n){ return n%1000000007; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
int32_t main(){
  DESYNC;
  
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  do {
    bool ok = true;
    int l = 0, r = 99999999;
    int ans = 0;
    for(int x : v){
      ans += x;
      if(ans < l || ans > r){
        ok = false;
        break;
      }
    }
    if(ok){
      for(int x : v){
        cout << x << endl;
      }
      return 0;
    }
  } while(next_permutation(v.begin(), v.end()));
  cout << "Error" << endl;
}
