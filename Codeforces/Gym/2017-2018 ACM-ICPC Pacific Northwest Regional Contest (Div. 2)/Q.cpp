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
 
/* Use upper_bound to swap to longest non decreasing subsequence */
 
 
int32_t main(){
  DESYNC;
 
  int n;
  cin >> n;
  int tot = (n-1)*(1+(n-1))/2;
  //cout << tot << endl;
  int hf = (tot+1)/2;
  int ini = 0, end = n;
  //cout << hf << endl;
  while(ini < end) {
    int mid = (ini+end)/2;
    int don = tot-((n-1-mid)*(1+(n-1-mid))/2);
    //cout << mid << " " << don << endl;
    if(don < hf) ini = mid+1;
    else end = mid;
  }
  cout << ini << endl;
}
 
