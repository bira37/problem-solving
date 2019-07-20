#include <bits/stdc++.h>
 
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
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
set<int> ans;
set<int> cur;
 
int32_t main(){
  int n;
  scanf("%I64d", &n);
  for(int i=0; i<n; i++){
    int x;
    scanf("%I64d", &x);
    set<int> new_cur;
    for(int k : cur){
      new_cur.insert(gcd(k, x));
      ans.insert(gcd(k, x));
    }
    cur.clear();
    new_cur.insert(x);
    ans.insert(x);
    swap(cur, new_cur);
  }
  cout << ans.size() << endl;
}
 
