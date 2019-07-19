#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define ff first
#define ss second
using namespace std;

int legendre(int n, int p){
  int cur = p;
  int cnt = 0;
  while(cur <= n){
    cnt += n/cur;
    cur *=p;
  }
  return cnt;
}

vector< ii > f;

int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  int test = 1;
  while(t--){
    int n, k;
    cin >> n >> k;
    f.clear();
    for(int i=2; i<=sqrt(k); i++){
      if(k%i == 0){
        f.push_back(ii(i, 0));
        while(k%i == 0){
          k/=i;
          f.back().ss++;
        }
      }
    }
    if(k != 1) f.push_back(ii(k, 1));
    int ans = LLONG_MAX;
    for(ii p : f){
      ans = min(legendre(n, p.ff)/p.ss, ans);
    }
    cout << "Case " << test++ << ": " << ans << endl;
  }
}
  
      
      
  
