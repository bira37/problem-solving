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
const double PI = acos(-1);

using namespace std;

inline int mod(int n){ return (n%1000000007); }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

set<int> s, aux;

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int s;
  int a,b;
  int v1[n], v2[n];
  cin >> a >> b;
  v1[0] = a, v2[0] = b;
  s = a*b;
  for(int i=1; i<n; i++){
    cin >> a >> b;
    v1[i] = a, v2[i] = b;
    s = gcd(s, a*b);
  }
  if(s == 1){
    cout << -1 << endl;
    return 0;
  }
  for(int i=0 ; i<n; i++){
    if(gcd(s, v1[i]) != 1) s = gcd(s,v1[i]);
    else s = gcd(s, v2[i]);
  }
  cout << s << endl;
}

