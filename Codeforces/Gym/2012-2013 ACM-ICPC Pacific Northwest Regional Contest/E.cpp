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
  
  int G;
  cin >> G;
 
  for(int g = 0; g < G; g++) {
    int N, R;
    cin >> N >> R;
    
    bitset<101> rr[2][N+1];
    
    bool nullr = false;
    bool missr = false;    
    bool repr = false;        
    int po;
    for(int r = 0; r < R; r++) {
      int fre[N+1];
      memset(fre, 0, sizeof fre);
      for(int n = 0; n < 3; n++) {
        cin >> po;
        if(po == 0) {
          nullr = true;
        }
        if(abs(po) > N) {
          missr = true;
        }
        if(nullr || missr || repr)
          continue;
        fre[abs(po)]++;
        if(fre[abs(po)] > 1) {
          repr = true;
        }
        if(nullr || missr || repr)
          continue;
        rr[(po>0)][abs(po)][r] = 1;
      }
      cin >> po;
    }
    
    if(nullr) {
      cout << "INVALID: NULL RING" << endl;
      continue;
    }
    if(missr) {
      cout << "INVALID: RING MISSING" << endl;
      continue;
    }
    if(repr) {
      cout << "INVALID: RUNE CONTAINS A REPEATED RING" << endl;
      continue;
    }
    
    bool good = false;
    for(int i = 0; i < (1<<N); i++) {
      bitset<101> E;
      
      for(int j = 0; j < N; j++) {
        int po = j + 1;
        int st;
        if(i & (1<<j)) {
          st = 1;
        } else {
          st = 0;
        }
        E |= rr[st][po];
      }
      if(E.count() == R) {
          good = true;
          break;
      }
    }
    if(good) {
      cout << "RUNES SATISFIED!" << endl;
    } else {
      cout << "RUNES UNSATISFIABLE! TRY ANOTHER GATE!" << endl;
    }
  }
}
 
