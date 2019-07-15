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
  int n,k;
  cin >> n >> k;
  if(n == k){
    string s;
    for(int i=0; i<n; i++) s += '0';
    cout << s << endl;
  }
  else if(k == 1){
    string s;
    s += '0';
    while(s.size() < n) s += '1';
    cout << s << endl;
  }
  else {
    int qtd = (n-k)/2;
    string s;
    while(s.size() < n){
      for(int i=0; i<qtd && s.size() < n; i++){
        s += '0';
      }
      if(s.size() < n) s += '1';
    }
    cout << s << endl;
  }
  
}

