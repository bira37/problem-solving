#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long

bool check(int n, int m){
  int need = (n+1)/2ULL;
  int cur = 0;
  while(n > 0){
    int tira = min(n, m);
    n -= tira;
    cur += tira;
    tira = min(n, (10ULL*n)/100ULL);
    n -= tira;
  }
  return need <= cur;
}

int32_t main(){
  int n;
  cin >> n;
  
  int l = 1, r = (int)1e18;
  int ans = 0ULL;
  while(l <= r){
    int m = (l+r)>>1;
    if(check(n, m)){
      ans = m;
      r = m-1ULL;
    }
    else l = m+1ULL;
  }
  cout << ans << endl;
}