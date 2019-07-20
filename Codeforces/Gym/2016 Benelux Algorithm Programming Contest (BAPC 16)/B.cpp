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
  string ans;
  set< string > t;
  t.insert("RBL");
  t.insert("RLB");
  t.insert("BRL");
  t.insert("BLR");
  t.insert("LBR");
  t.insert("LRB");
  for(int i=0; i<s.size(); i++){
    if(i+2 < s.size()){
      string k;
      k+= s[i];
      k += s[i+1];
      k += s[i+2];
      if(t.count(k)){
        ans += 'C';
        i+=2;
        continue;
      }
    }
    if(s[i] == 'R') ans += 'S';
    else if(s[i] == 'B') ans += 'K';
    else ans += 'H';
  }
  cout << ans << endl;
}
 
