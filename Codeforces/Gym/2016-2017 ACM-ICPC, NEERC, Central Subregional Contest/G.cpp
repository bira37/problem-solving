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
 // DESYNC;
  
  ifstream cin("input.txt");
  ofstream cout("output.txt");
  
  int n;
  cin >> n;
  
  int ans = 0;
  for(int i = 2; i <= sqrt(n); i++) {
    if(n%i==0) {
      
    }
    int cnt = 0;
    while(n%i==0) {
      cnt++;
      n/=i;
    }
    if(cnt>1) {
      cout << "NO" << endl;
      return 0;
    } else if(cnt == 1) {
      ans++;
    }
  }
  if(n != 1) {
    ans++;
  }
  
  if(ans == 3) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  
}
 
