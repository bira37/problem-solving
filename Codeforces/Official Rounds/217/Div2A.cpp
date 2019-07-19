#include <bits/stdc++.h>
 
#define int long long
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
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int32_t main(){
  DESYNC;
  int xa,ya,xb,yb;
  cin >> xa >> ya >> xb >> yb;
  //rook
  int ans1 = (abs(xa-xb) != 0) + (abs(ya-yb) != 0);
  
  //bishop
  int ans2 = 0;
  if(abs(xa-xb) == 0 && abs(ya-yb) == 0) ans2 = 0;
  else if(abs(xa-xb) == abs(ya-yb)) ans2 = 1;
  else if(abs(xa-xb)%2 == abs(ya-yb)%2) ans2 = 2;
  else ans2 = 0;
  
  //king
  int ans3 = 0;
  ans3 = min(abs(xa-xb), abs(yb-ya)) + (abs(xa-xb) + abs(ya-yb) - 2*min(abs(xa-xb), abs(yb-ya)));
  
  cout << ans1 << " " << ans2 << " " << ans3 << endl;
}
