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
  int n;
  cin >> n;
  bool f1 = false, f2 = false;
  bool mrk[10];
  for(int i=0; i<10; i++) mrk[i] = false;
  while(n--){
  	char c;
  	cin >> c;
  	mrk[c-'0'] = true;
  }
  if((mrk[1] || mrk[2] || mrk[3]) && mrk[0]){
  	cout << "YES" << endl;
  	return 0;
  }
  if((mrk[1] || mrk[2] || mrk[3]) && (mrk[7] || mrk[9])) f1 = true;
  if((mrk[1] || mrk[4] || mrk[7]) && (mrk[3] || mrk[6] || mrk[9])) f2 = true;
  if(f1 && f2){
  	cout << "YES" << endl;
  	return 0;
  }
  cout << "NO" << endl;
}
 
