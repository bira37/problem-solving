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
  int q;
  cin >> q;
  while(q--){
    string s,t;
    int n;
    cin >> n;
    cin >> s >> t;
    vector<int> er;
    for(int i=0; i<n; i++){
      if(s[i] != t[i]) er.pb(i);
    }
    if(er.size() != 2){
      cout << "No" << endl;
      continue;
    }
    if(s[er[0]] == s[er[1]] and t[er[1]] == t[er[0]]){
      cout << "Yes" << endl;
    }
    else cout << "No" << endl;
  }
}

 
