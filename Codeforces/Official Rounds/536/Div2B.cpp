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

struct food{
  int idx, price, qtd;
  food(){}
  food(int idx, int price, int qtd) : idx(idx), price(price), qtd(qtd) {}
  bool operator<(const food & f) const {
    return price < f.price || (price == f.price && idx < f.idx);
  }
};

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  vector<food> v(n);
  int id[n];
  for(int i=0; i<n; i++){
    v[i].idx = i;
    cin >> v[i].qtd;
  }
  for(int i=0; i<n; i++){
    v[i].idx = i;
    cin >> v[i].price;
  }
  int ans = 0;
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for(int i=0; i<n; i++){
    id[v[i].idx] = i;
  }
  while(m--){
    int t,d;
    cin >> t >> d;
    t--;
    int cur = 0;
    if(id[t] < v.size()){
      int tira = d;
      tira = min(tira, v[id[t]].qtd);
      cur += tira*v[id[t]].price;
      d -= tira;
      v[id[t]].qtd -= tira;
    }
    while(d > 0 && v.size() > 0){
      int tira = d;
      tira = min(tira, v.back().qtd);
      cur += tira*v.back().price;
      d -= tira;
      v.back().qtd -= tira;
      if(v.back().qtd == 0) v.pop_back();
    }
    cur =  cur*(d == 0);
    cout << cur << endl;
  }
}

