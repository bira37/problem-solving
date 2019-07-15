#include <bits/stdc++.h>
  #define MAX_N (long long)1e18
  using namespace std;
  #define int long long
  set<long long> s;
  vector<long long> v;
  void process(){
    for(long long i=2; i<=1000000LL; i++){
      for(long long j=i*i*i; j<=MAX_N; j*=i){
        s.insert(j);
        if(j > MAX_N/i) break;
      }
    }
    s.insert(1LL);
    for(long long x : s){
      if((long long)sqrt(x)*(long long)sqrt(x) == x) continue;
      v.push_back(x);
    }
  }
   
  long long query(long long l, long long r){
    long long ans = 0;
    int ll = 0, rr = v.size()-1;
    int ansl = 11234567, ansr = 11234567;
    while(ll <= rr){
      int m = (ll+rr) >> 1;
      if(v[m] >= l){
        if(v[m] <= r) ansl = m;
        rr = m-1;
      }
      else ll = m+1;
    }
    ll = 0, rr = v.size()-1;
    while(ll <= rr){
      int m = (ll+rr) >> 1;
      if(v[m] <= r){
        if(v[m] >= l) ansr = m;
        ll= m+1;
      }
      else rr = m-1;
    }
    ans += max(0LL, ansr-ansl+1);
    if(ansl == 11234567) ans--;
    ans += (long long)sqrt(r) - (long long)sqrt(l-1);
    return ans;
  }
  int32_t main() {
    int q;
    scanf("%lld", &q);
    process();
    while(q--){
      long long l, r;
      scanf("%lld%lld", &l, &r);
      printf("%lld\n", max(0LL,query(l,r)));
    }
   
  }