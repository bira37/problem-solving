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
 
int calc(string s, int k){
  
  int cnt = 0;
  int l = 0, r = 0;
  cnt = (s[0] == 'b');
  int ret = 1;
  while(r < (int)s.size()-1){
    r++;
    cnt += (s[r] == 'b');
    while(cnt > k){
      cnt -= (s[l++] == 'b');
    }
    ret = max(ret, r-l+1);
  }
  return ret;
}  
 
int32_t main(){
  DESYNC;
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  s = s;
  
  if(k > 0){
    int ans = calc(s, k);
    for(int i=0; i<n; i++){
      if(s[i] == 'a') s[i] = 'b';
      else s[i] = 'a';
    }
    ans = max(ans, calc(s, k));
    
    cout << ans << endl;
  }
  else {
    int cur = 1;
    int ans = 1;
    char last = '0';
    for(char c : s){
      if(c == last){
        cur++;
        ans = max(cur, ans);
        last = c;
      }
      else {
        cur = 1;
        last = c;
      }
    }
    cout << ans << endl;
  }
    
}
 
