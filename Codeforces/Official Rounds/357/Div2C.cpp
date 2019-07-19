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
  int n;
  cin >> n;
  vector<string> ans;
  priority_queue<int, vector<int>, greater<int> > s;
  for(int i=0; i<n; i++){
    string a;
    cin >> a;
    if(a == "getMin"){
      int b;
      cin >> b;
      while(s.size() > 0 && s.top() < b){
        s.pop();
        ans.pb("removeMin");
      }
      if(s.size() <= 0 || s.top() > b){
        ans.pb("insert " + to_string(b));
        s.push(b);
      }
      ans.pb(a + " " + to_string(b));
    }
    else if(a == "insert"){
      int b;
      cin >> b;
      s.push(b);
      ans.pb(a + " " + to_string(b));
    }
    else {
      if(s.size() == 0){
        ans.pb("insert 1");
      }
      else s.pop();
      ans.pb(a);
    }
  }
  cout << ans.size() << endl;
  for(string k : ans) cout << k << endl;      
}
