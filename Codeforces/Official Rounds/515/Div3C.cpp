#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

typedef tree<
ii, //change for pair<int,int> to use like multiset
null_type,
less< ii >, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int32_t main(){
  DESYNC;
  ordered_set s;
  map<int,int> m;
  int q;
  cin >> q;
  while(q--){
    char op;
    int x;
    cin >> op >> x;
    if(op == 'L'){
      if(s.size() == 0){
        m[x] = 0;
        s.insert(ii(m[x], x));
      }
      else m[x] = s.begin()->ff-1;
      s.insert(ii(m[x], x));
    }
    else if(op == 'R'){
      if(s.size() == 0){
        m[x] = 0;
        s.insert(ii(m[x], x));
      }
      else m[x] = s.rbegin()->ff+1;
      s.insert(ii(m[x], x));
    }
    else {
      int pos = s.order_of_key(ii(m[x], x));
      //cout << pos << " " << s.size() << endl;
      cout << min(pos, (int)s.size()-pos-1) << endl;
    }
  }
}

