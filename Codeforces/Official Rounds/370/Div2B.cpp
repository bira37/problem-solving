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
  int L = 0, R = 0, U = 0, D = 0;
  cin >> s;
  int n = s.size();
  if(n%2 != 0){
    cout << -1 << endl;
    return 0;
  }
  int posx = 0;
  int posy = 0;
  for(char c : s){
    if(c == 'L') posy--;
    else if(c == 'R') posy++;
    else if(c == 'U') posx++;
    else posx--;
  }
  cout << (abs(posx) + abs(posy))/2 << endl;
}
 
