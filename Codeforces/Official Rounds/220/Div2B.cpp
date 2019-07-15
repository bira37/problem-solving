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
  int ansi = 1, ansp = 1;
  vector<string> cu;
  string t;
  int p =0;
  while(p < s.size()-1){
    if(s[p] + s[p+1] - 2*'0' == 9){
      if(t == "") t += s[p];
      t += s[p+1];
      p++;
    }
    else {
      if(t != "") cu.pb(t);
      t = "";
      p++;
    }
  }
  if(t != "") cu.pb(t);
  vector<string> cu2;
  for(int i=0; i<cu.size(); i++){
    if(cu[i].size()%2) cu2.pb(cu[i]);
    else if(cu2.size() > 0 && cu[i].size()%2 == 0 && cu2.back().size()%2 == 0) cu2.back() += cu[i];
    else cu2.pb(cu[i]);
  }
  int desgraca = 1;
  for(string t : cu2){
    desgraca*=(t.size()%2 == 0 ? 1 : (t.size()+1)/2);
  }
  cout << desgraca << endl;
}