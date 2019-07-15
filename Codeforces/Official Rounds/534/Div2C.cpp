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
  bool f0 = false, f1 = false;
  for(char c : s){
    if(c == '0'){
      if(f0){
        cout << "3 1" << endl;
      }
      else cout << "1 1" << endl;
      f0 = !f0;
    }
    else {
      if(f1) cout << "3 1" << endl;
      else cout << "3 3" << endl;
      f1 = !f1;
    }
  }   
}

