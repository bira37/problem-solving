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

struct Manacher{
  
  vector<int> d_e, d_o;
  Manacher(){}
  
  Manacher(int n){
    d_e.resize(n);
    d_o.resize(n);
  }
  
  void calculate(string & s){
    
    int n = d_e.size();
    //calculate for odd
    for (int i = 0, l = 0, r = -1; i < n; i++) {
      d_o[i] = (i > r) ? 1 : min(d_o[l + r - i], r - i + 1);
      while(i - d_o[i] >= 0 and i + d_o[i] < n and s[i-d_o[i]] == s[i+d_o[i]]) d_o[i]++;
      if(i + d_o[i]-1 > r){
        l = i-d_o[i]+1;
        r = i+d_o[i]-1;
      }
    }
    
    //calculate for even
    for (int i = 0, l = 0, r = -1; i < n; i++) {
      d_e[i] = (i > r) ? 0 : min(d_e[l + r - i + 1], r - i + 1);
      while(i - d_e[i] - 1 >= 0 and i + d_e[i] < n and s[i-d_e[i]-1] == s[i+d_e[i]]) d_e[i]++;
      if(i + d_e[i]-1 > r){
        l = i-d_e[i];
        r = i+d_e[i]-1;
      }
    }
    
  }
  
};

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  string s;
  cin >> s;
  Manacher m(n);
  m.calculate(s);
  int ans = 0;
  for(int i=0; i<n; i++){
    ans = max(ans, m.d_o[i]*2-1);
    ans = max(ans, m.d_e[i]*2);
  }
  cout << ans << endl;
}


