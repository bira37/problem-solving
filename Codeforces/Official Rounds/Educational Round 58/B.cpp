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
  string s;
  cin >> s;
  bool flag = false;
  int l = -1;
  for(int i=0; i<s.size(); i++){
    if(flag && s[i] == ':'){
      l = i;
      break;
    }
    else if(!flag && s[i] == '['){
      flag = true;
    }
  }
  flag = false;
  int r = -1;
  reverse(s.begin(), s.end());
  for(int i=0; i<s.size(); i++){
    if(flag && s[i] == ':'){
      r = (int)(s.size())-1-i;
      break;
    }
    else if(!flag && s[i] == ']'){
      flag = true;
    }
  }
  if(l == -1 || r == -1 || l >= r){
    cout << -1 << endl;
    return 0;
  }
  int ans = 4;
  reverse(s.begin(), s.end());
  for(int i=l+1; i < r; i++) ans += (s[i] == '|');
  cout << ans << endl;
}

