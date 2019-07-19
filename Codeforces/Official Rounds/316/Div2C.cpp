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
 
set<int> s;
string t;
int ans;
 
int calc(int l, int r){
  int contrib = (r-l+1)-3;
  return max(contrib, 0LL);
}
 
void add_letter(int idx){
  auto it = s.upper_bound(idx);
  int r = *it;
  it--;
  int l = *it;
  ans -= calc(l,r);
  ans += calc(l, idx);
  ans += calc(idx, r);
  s.insert(idx);
}
 
void remove_letter(int idx){
  auto it = s.lower_bound(idx);
  it--;
  int l = *it;
  it++;
  it++;
  int r = *it;
  ans -= calc(l, idx);
  ans -= calc(idx, r);
  ans += calc(l, r);
  it--;
  s.erase(it);
}
  
int32_t main(){
  DESYNC;
  int n,q;
  cin >> n >> q;
  cin >> t;
  s.insert(0);
  s.insert(n+1);
  ans = n-1;
  for(int i=1; i<=n; i++){
    if(t[i-1] != '.'){
      add_letter(i);
    }
  }
  while(q--){
    int idx;
    char c;
    cin >> idx >> c;
    if(c == '.'){
      //remove
      if(s.count(idx)) remove_letter(idx);
    }
    else {
      if(!s.count(idx)) add_letter(idx);
    }
    cout << ans << endl;
  }
}
 
