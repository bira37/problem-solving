#include <bits/stdc++.h>
 
#define int long long
#define ff first
#define ss second
#define endl '\n'
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define EPS 1e-9
#define INF (int)1e18
#define ROOT 1
 
using namespace std;
 
inline int mod(int n){ return n%1000000007; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
int32_t main(){
  DESYNC;
  int w, a,b;
  cin >> w >> a >> b;
  
  int l = 0;
  if(
   ((a == 2 && b == 4) || (a == 4 && b == 2))
   || (((a == 1) ^ (b == 1)) == 1)
   || (a % 2 != b%2)) {
    cout << "Impossible" << endl;
  } else  {
      cout << "Possible" << endl;
      int be;
      if(a < b) be = a-1;
      else be = b-1;
      
      int diff = abs(a-b)/2;
      for(int i = 1; i <= w; i++) {
        if(a < b) {
          if(a-i == 1 && diff) cout << '*';
          else if(i == a) cout << 'A';
          else cout << '.';
        } else {
          if(i == a) cout << 'A';
          else cout << '.';
        }
         
      }
      cout << endl;
      
      int aux = diff;
      for(int i = 1; i <= w; i++) {
         if(i >= be && aux) {
          if(i == 1) cout << 'X';
          else cout << '*';
          aux--;
         }
         else {
          if(i == 1) cout << 'X';
          else cout << '.';
         }
      }
      cout << endl;
      
      for(int i = 1; i <= w; i++) {
        if(b < a) {
          if(b-i == 1 && diff) cout << '*';
          else if(i == b) cout << 'B';
          else cout << '.';
        } else {
          if(i == b) cout << 'B';
          else cout << '.';
        }
      }
      cout << endl;
  }
 
}
