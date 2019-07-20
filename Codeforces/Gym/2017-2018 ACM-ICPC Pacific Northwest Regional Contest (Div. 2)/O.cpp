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
  
  int n;
  
  while(cin >> n){
  
  string st[n];
  for(int i = 0; i < n; i++) {
    cin >> st[i];
  }
  
  bool good = true;
  
  // check rows
  for(int i = 0; i < n; i++) {
    set<char> se;
    for(int j = 0; j < n; j++) {
      se.insert(st[i][j]);
    }
    if(se.size() != n) {
      good = false;
    }
  }
  
  // check cols
  for(int i = 0; i < n; i++) {
    set<char> se;
    for(int j = 0; j < n; j++) {
      se.insert(st[j][i]);
    }
    if(se.size() != n) {
      good = false;
    }
  }
  
  if(!good) {
    cout << "No" << endl;
    continue;
  }
  
  bool good2 = true;
  
  //check f row and col
  string ord = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i = 0; i < n; i++) {
    if(st[0][i] != ord[i]) good2 = false;
  }
  
  for(int i = 0; i < n; i++) {
    if(st[i][0] != ord[i]) good2 = false;
  }
  
  if(good2) {
    cout << "Reduced" << endl;
  } else {
    cout << "Not Reduced" << endl;
  }
  }
}
 
