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
  ifstream cin("input.txt");
  ofstream cout("output.txt");
  
  int n, k;
  cin >> n >> k;
  
  int a[n];
  int ai = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] > a[ai]) ai = i;
  }
  int ax = a[ai];
  
  int sx = 0, ss = 0;
  for(int i = 0; i < n; i++) {
    if(i < ai) sx += a[i];
    if(i != ai) ss += a[i];
  }
  
    
  int ini = -1, end = 1e8+100;
  while(ini < end) {
    int mid = (ini+end)/2;
    // cout << ini << " " << end << " " << mid << endl;
    int lft = k-(mid*ax);
    //cout << lft << endl;
    //cout << ai + (n-1)*(mid) << endl;
    //cout << sx + ss*mid << endl;
    if(lft < ai + (n-1)*(mid)) end = mid-1;
    else if(lft > sx + ss*mid) ini = mid+1;
    else {
      cout << "YES" << endl;
      return 0;
    }
  }
  int mid = ini;
  int lft = k-(mid*ax);
  if(lft < ai + (n-1)*(mid)) end = mid-1;
  else if(lft > sx + ss*mid) ini = mid+1;
  else {
    cout << "YES" << endl;
    return 0;
  }
  cout << "KEK" << endl;
}
 
