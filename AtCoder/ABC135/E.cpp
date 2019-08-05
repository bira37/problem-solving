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
  int k,x,y;
  cin >> k >> x >> y;
  
  //check
  if(k%2 == 0 && (abs(x) + abs(y))%2 == 1){
    cout << -1 << endl;
    return 0;
  }
  
  int cx = 0, cy = 0;
  // calculate N
  int N = (abs(x) + abs(y) + k-1)/k + (abs(x) + abs(y) <= k && abs(x) + abs(y) != k);
  //fix N
  while((N*k)%2 != (abs(x)+abs(y))%2) N++;
  
  int B = (N*k - abs(x) - abs(y))/2;
  
  cout << N << endl;
  
  while(B > 0){
    bool less = abs(x - cx) < abs(y - cy);
    
    if(B > k){
      if(less){
        if(x >= 0) cx -= k;
        else cx += k;
      }
      else {
        if(y >= 0) cy -= k;
        else cy += k;
      }
      B -= k;
    }
    else {
      if(less){
        if(x >= 0) cx -= B;
        else cx += B;
        if(y >= 0) cy += (k - B);
        else cy -= (k - B);
        B = 0;
      }
      else {
        if(y >= 0) cy -= B;
        else cy += B;
        if(x >= 0) cx += (k - B);
        else cx -= (k - B);
        B = 0;
      }
    }
    
    cout << cx << " " << cy << endl;
  }
  
  //deal with upmoves
  while(cx != x or cy != y){
    int have = k;
    if(cx != x){
      int need = min(have, abs(cx-x));
      if(cx < x) cx += need;
      else cx -= need;
      have -= need;
    }
    if(cy != y){
      int need = min(have, abs(cy-y));
      if(cy < y) cy += need;
      else cy -= need;
      have -= need;
    }
    assert(have == 0);
    cout << cx << " " << cy << endl;
  }
}
