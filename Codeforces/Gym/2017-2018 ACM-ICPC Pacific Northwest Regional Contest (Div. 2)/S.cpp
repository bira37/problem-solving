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
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int32_t main(){
  DESYNC;
  string s;
  cin >> s;
  int n = s.size();
  int bst = 1;
  ii ans(0,0);
  int cur = 0;
  int l = 0;
  for(int r=0; r<n; r++){
    cur += (s[r] == 'R' ? 1 : -1);
    if(cur > bst){
      bst = cur;
      ans = ii(l,r);
    }
    if(cur < 0){
      l = r+1;
      cur = 0;
    }
  }
  cur = 0;
  l = 0;
  for(int r=0; r<n; r++){
    cur += (s[r] == 'B' ? 1 : -1);
    if(cur > bst){
      bst = cur;
      ans = ii(l,r);
    }
    if(cur < 0){
      l = r+1;
      cur = 0;
    }
  }
  
  cur = 0;
  int r = n-1;
  for(int l = n-1; l >= 0; l--){
     cur += (s[l] == 'B' ? 1 : -1);
     if(cur > bst || (cur == bst && (l < ans.ff || l == ans.ff && r < ans.ff))){
      bst = cur;
      ans = ii(l,r);
    }
    if(cur < 0){
      r = l-1;
      cur = 0;
    }
  }
  
  cur = 0;
  r = n-1;
  for(int l = n-1; l >= 0; l--){
     cur += (s[l] == 'R' ? 1 : -1);
     if(cur > bst || (cur == bst && (l < ans.ff || l == ans.ff && r < ans.ff))){
      bst = cur;
      ans = ii(l,r);
    }
    if(cur < 0){
      r = l-1;
      cur = 0;
    }
  }
  
  cout << ans.ff+1 << " " << ans.ss+1 << endl;
}
 
