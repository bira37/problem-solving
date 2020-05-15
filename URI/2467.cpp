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



struct blabla{
  int n, q, c;
  vector<int> time_row, time_col, color_col, color_row;
  vector<BIT> bit;
  blabla(int n, int q, int c) : n(n), q(q), c(c){
    time_row = vector<int>(n, -1);
    time_col = vector<int>(n, -1);
    color_row = vector<int>(n, 0);
    color_col = vector<int>(n, 0);
    bit.resize(c);
    for(int i=0; i<c; i++){
      bit[i] = BIT(q);
    }
  }
  
  //update line
  void update_line(int qry, int x, int val){
    color_row[x] = val;
    time_row[x] = qry;
  }
  
  void update_col(int qry, int x, int val){
    if(time_col[x] != -1){
      bit[color_col[x]].update(time_col[x], -1);
    }
    time_col[x] = qry;
    color_col[x] = val;
    bit[val].update(time_col[x], 1);
  }
  
  int query(int x){
    int ret = -1;
    int qtd = -1;
    int sum = 0;
    for(int color = 0; color < c; color++){
      if(color_row[x] == color) continue;
      int cnt = bit[color].query(time_row[x], q);
      sum += cnt;
      if(cnt >= qtd){
        qtd = cnt;
        ret = color;
      }
    }
    if(n - sum > qtd || (n-sum == qtd && color_row[x] > ret)){
      qtd = n - sum;
      ret = color_row[x];
    }
    return ret;
  }
};

int32_t main(){
  DESYNC;
  int n,q;
  cin >> n >> q;
  blabla rows(n, q, 51), cols(n, q, 51);
  for(int qry = 1; qry <= q; qry++){
    int op;
    cin >> op;
    if(op == 1){
      int x, r;
      cin >> x >> r;
      x--;
      rows.update_line(qry, x, r);
      cols.update_col(qry, x, r);
    }
    else if(op == 2){
      int x,r;
      cin >> x >> r;
      x--;
      cols.update_line(qry, x, r);
      rows.update_col(qry, x, r);
    }
    else if(op == 3){
      int x;
      cin >> x;
      x--;
      cout << rows.query(x) << endl;
    }
    else {
      int x;
      cin >> x;
      x--;
      cout << cols.query(x) << endl;
    }
  }
}


