#include <bits/stdc++.h>
 
#define int unsigned long long
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
#define INF ULLONG_MAX
#define ROOT 1
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int b;
vector<int> divisors;
map<int,int> memo;
 
int go(int k){
  if(memo.count(k)) return memo[k];
  if(k < b) return k;
  int best = INF;
  for(int d : divisors){
    if(k%d > 0) continue;
    int x = k/d;
    if(x%d == 0 && d*d < b) continue;
    int a = go(x);
    if(a == INF) continue;
    if(a > (LLONG_MAX - d)/b) continue; 
    best = min(best, a*b + d);
  }
  memo[k] = best;
  return best;
}
 
int32_t main(){
  DESYNC;
  int n;
  cin >> b >> n;
  set<int> s;
  for(int i=2; i<b; i++){
    if(n%i == 0 && i*i >= b){
      divisors.pb(i);
      s.insert(i);
    }
  }
  if(n >= INT_MAX){
    for(int d : divisors){
      for(int i = 2; i<=sqrt(d); i++){
        if(d%i == 0){
          if(s.count(i)) s.erase(s.find(i));
          if(s.count(d/i)) s.erase(s.find(d/i));
        }
      }
    }
  }
  divisors.clear();
  for(int x : s) divisors.pb(x);
  sort(divisors.begin(), divisors.end(), greater<int>());
  int ans = go(n);
  if(ans == INF) cout << "impossible" << endl;
  else cout << ans << endl;
}
