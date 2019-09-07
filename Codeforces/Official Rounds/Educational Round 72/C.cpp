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
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int n = s.size();
    int offset = -1;
    for(int i=0; i<n; i++){
      if(s[i] == '1') break;
      offset = i;
    }
    int ans = 0;
    int lst[n];
    if(s[0] == '1') lst[0] = 0;
    else lst[0] = -1;
    for(int i=1; i<n; i++){
      if(s[i] == '1') lst[i] = i;
      else lst[i] = lst[i-1];
    } 
    for(int i=offset+1; i <n; i++){
      int acc = 0;
      int sz = 0;
      int pot = 0;
      int j;
      for(j=i; j>offset and j > i-22 and j >= 0; j--){
        if(pot == 0) pot=1;
        else pot *= 2LL;
        sz++;
        if(s[j] == '1') acc += pot;
        if(acc == sz) ans++;
      }
      if(j == offset){
        if(acc > sz and sz + offset+1 >= acc) ans++;
      }
      else {
        if(acc > sz and sz + j - lst[j] >= acc) ans++;
      }    
    }
    cout << ans << endl; 
  }
}
