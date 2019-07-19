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
  cin >> n;
  map<int,bool> lef, rig;
  int root;
  cin >> root;
  set<int> s;
  s.insert(root);
  for(int i=0; i<n-1; i++){
    int cur;
    cin >> cur;
    auto it = s.lower_bound(cur);
    int l = -1, r = -1;
    if(it != s.end()){
      r = *it;
    }
    if(it != s.begin()){
      --it;
      l = *it;
    }
    if(l == -1){
      rig[r] = true;
      cout << r << " ";
    }
    else if(r == -1){
      lef[l] = true;
      cout << l << " ";
    }
    else {
      if(lef[l]){
        rig[r] = true;
        cout << r << " ";
      }
      else {
        lef[l] = true;
        cout << l << " ";
      }
    }
    s.insert(cur);
  }
  cout << endl;
}
 
