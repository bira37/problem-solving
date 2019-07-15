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

int q = 0;
map<int,int> divs;
vector<bool> vis(1123456, false);

void count_divs(int x){
  divs[x]++;
  for(int i = 2; i<=sqrt(x); i++){
    if(x%i == 0){
      divs[i]++;
      if(x/i != i) divs[x/i]++;
    }
  }
}

int ask_x(int x){
  cout << "> " << x << endl;
  cout.flush();
  q++;
  assert(q <= 60);
  int a;
  cin >> a;
  return a;
}

int ask_i(int i){
  cout << "? " << i << endl;
  cout.flush();
  q++;
  assert(q <= 60);
  int a;
  cin >> a;
  return a;
}

int32_t main(){
  int n;
  cin >> n;
  srand(time(0));
  int l = 0, r = (int)1e9;
  int greatest = r;
  while(l <= r){
    int m = (l+r)/2;
    if(ask_x(m) == 1){
      l = m+1;
    }
    else {
      greatest = m;
      r = m-1;
    }
  }
  int visited = 0;
  int counted = 0;
  while(q < 60 && visited < n){
    int id = (rand()*rand())%n;
    while(vis[id]) id = (rand()*rand())%n;
    vis[id] = true;
    visited++;
    int x = ask_i(id+1);
    if(x != greatest) count_divs(greatest - x);
    if(x != greatest) counted++;
  }
  int d = 1;
  int mx = 0;
  for(auto p : divs){
    if(p.ss >= mx && greatest - (n-1)*d >= 0 && p.ss == counted){
      mx = p.ss;
      d = p.ff;
    }
  }
  cout << "! " << greatest - (n-1)*d << " " << d << endl;
  cout.flush();
}

