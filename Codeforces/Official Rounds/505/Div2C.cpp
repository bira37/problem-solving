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

int32_t main(){
  DESYNC;
  string s;
  cin >> s;
  s = s+s;
  int mx = 0;
  int cur = 1;
  int st = 0;
  int n = s.size()/2;
  for(int i=1; i<s.size(); i++){
    if(st%n != i%n && s[i-1] != s[i]) cur++;
    else {
      st = i;
      mx = max(mx, cur);
      cur = 1;
    }
  }
  mx = max(mx, cur);
  cout << mx << endl;
}

