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
  DESYNC;
  string S, T;
  cin >> S >> T;
  int n = S.size();
  int m = T.size();
  int p[n+10], s[n+10];
  p[0] = (S[0] == T[0]);
  for(int i=1; i<n; i++){
    p[i] = p[i-1] + (S[i] == T[p[i-1]]);
  }
  s[n-1] = (S[n-1] == T[m-1]);
  for(int i=n-2; i>=0; i--){
    s[i] = s[i+1] + (S[i] == T[m-1-s[i+1]]);
  }
  int j = 0;
  int ans = 0;
  for(int i=0; i<n; i++){
    if(j <= i) j = i+1;
    while(j < n and p[i] + s[j] >= m) j++;
    j--;
    //cout << i << " " << j << endl;
    if(j >= n) break;
    if(p[i] + s[j] == m) ans = max(ans, (j-1)-(i+1)+1);
  }
  for(int i=0; i<n; i++){
    if(p[i] == m) ans = max(ans, (n-1)-i);
    if(s[i] == m) ans = max(ans, i);
  }
  cout << ans << endl;
}
