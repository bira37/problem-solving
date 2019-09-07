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

struct BIT {
  
  vector<int> bit;

  BIT() {}
  
  int n;
   
  BIT(int n) {
    this->n = n;
    bit.resize(n+1);
  }

  void update(int idx, int val){
    for(int i = idx; i <= n; i += i&-i){
      bit[i]+=val;
    }
  }

  int prefix_query(int idx){
    int ans = 0;
    for(int i=idx; i>0; i -= i&-i){
      ans += bit[i];
    }
    return ans;
  }
  
  int query(int l, int r){
    return prefix_query(r) - prefix_query(l-1);
  }
  
  //int bit 0-1 it finds the index of k-th element active
  int kth(int k) {
    int cur = 0;
    int acc = 0;
    for(int i = 19; i >= 0; i--) {
      if(cur + (1<<i) > n) continue;
      if(acc + bit[cur + (1<<i)] < k) {
        cur += (1<<i);
        acc += bit[cur];
      }
    }
    return ++cur;
  }
  
};



int32_t main(){
  int n;
  cin >> n;
  int v[n+1];
  for(int i=1; i<=n; i++){
    int x;
    cin >> x;
    v[x] = i;
  }
  BIT bit(n);
  int ans = 0;
  for(int i=n; i>=1; i--){
    
    int l = 1, r = v[i];
    int ansl1 = -1;
    while(l <= r){
      int m = (l+r)>>1;
      if(bit.query(m, v[i]) <= 1){
        if(bit.query(m, v[i]) == 1) ansl1 = m;
        r = m-1;
      }
      else l = m+1;
    }
    
    int ansl0 = 1;
    l = 1, r = v[i];
    while(l <= r){
      int m = (l+r)>>1;
      if(bit.query(m, v[i]) <= 0){
        ansl0 = m;
        r = m-1;
      }
      else l = m+1;
    }
    
    int ansr1 = -1;
    l = v[i], r = n;
    while(l <= r){
      int m = (l+r)>>1;
      if(bit.query(v[i], m) <= 1){
        if(bit.query(v[i], m) == 1) ansr1 = m;
        l = m+1;
      }
      else r = m-1;
    }   
    
    int ansr0 = n;
    l = v[i], r = n;
    while(l <= r){
      int m = (l+r)>>1;
      if(bit.query(v[i], m) <= 0){
        ansr0 = m;
        l = m+1;
      }
      else r = m-1;
    }
    //cout << "ansl0 " << ansl0 << " ansl1 " << ansl1 << " ansr0 " << ansr0 << " ansr1 " << ansr1 << endl;
    //cout << "update at " << v[i] << " " << i << endl;
    bit.update(v[i], 1);
    if(ansr1 != -1) ans += (ansr1 - ansr0)*(v[i] - ansl0+1)*i;
    if(ansl1 != -1) ans += (ansl0 - ansl1)*(ansr0 - v[i] + 1)*i;
  }
  cout << ans << endl;
}


