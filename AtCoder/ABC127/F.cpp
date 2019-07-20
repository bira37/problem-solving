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
    if(l > r) return 0;
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

struct query{
  int t,a,b,c;
};

typedef tree<
ii,
null_type,
less< ii >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int key = 0;

int32_t main(){
  DESYNC;
  int q;
  cin >> q;
  query queries[q];
  set<int> s;
  map<int,int> m;
  for(int i=0; i<q; i++){
    cin >> queries[i].t;
    if(queries[i].t == 1){
      cin >> queries[i].a >> queries[i].b;
      s.insert(queries[i].a);
    }
  }
  int n = s.size();
  vector<int> aux;
  for(int x : s) aux.pb(x);
  for(int i=0; i<q; i++){
    if(queries[i].t == 1){
      queries[i].c = lower_bound(aux.begin(), aux.end(),  queries[i].a) - aux.begin() + 1;
      m[queries[i].a] = queries[i].c;
    }
  }
  BIT bit(n+1);
  int cons = 0;
  ordered_set os;
  for(int i=0; i<q; i++){
    if(queries[i].t == 1){
      //add on ord_set
      os.insert(ii(queries[i].a, ++key));
      //add on sumtree
      bit.update(queries[i].c, queries[i].a);
      cons += queries[i].b;
    }
    else {
      int median = (os.size()+1)/2 -1;
      int l = 0, r = median;
      int ans = median;
      auto it = os.find_by_order(median);
      int x = it->ff;
      while(l <= r){
        int m = (l+r)>>1;
        int cur = os.find_by_order(m)->ff;
        if(cur == x){
          ans = m;
          r = m-1;
        }
        else if(cur < x){
          l = m+1;
        }
      }
      median = ans;  
      int val = cons;
      //cout << (x*(median+1) - bit.query(1, m[x])) << " " << (bit.query(m[x]+1, n) - x*((int)os.size() - median - 1))<<endl;
      val += (x*(median) - bit.query(1, m[x]-1));
      val += (bit.query(m[x], n) - x*((int)os.size() - median));
      cout << x << " " << val << endl;
    }
  }
}


