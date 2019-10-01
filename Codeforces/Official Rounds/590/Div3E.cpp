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
 
int32_t main(){
  int n,m;
  cin >> n >> m;
  vector<int> v(n+2, 0);
  int a[m];
  auto add = [&](int l, int r){
    if(r < l) swap(l,r);
    if(l == r) return;
    //x < l 
    v[1] += r-l;
    v[l] -= r-l;
  
    //x = l
    v[l] += r-1;
    v[l+1] -= r-1;    
    
    //l < x < r
    v[l+1] += r-l-1;
    v[r] -= r-l-1;
    
    //x = r
    v[r] += l;
    v[r+1] -= l;
    
    //r < x
    v[r+1] += r-l;
    v[n+1] -= r-l;
    
  };
  for(int i=0; i<m; i++) cin >> a[i];
  for(int i=0; i<m-1; i++){
    add(a[i], a[i+1]);
  }
  for(int i=1; i<=n; i++){
    v[i] += v[i-1];
    cout << v[i] << " ";
  }
  cout << endl;
}
