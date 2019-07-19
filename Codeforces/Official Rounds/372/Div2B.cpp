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
 
bool check(string s, string & t, int st){
  set<char> av;
  for(char c = 'A'; c <= 'Z'; c++){
    av.insert(c);
  }
  int q = 0;
  for(char c : s){
    if(c == '?') q++;
    else if(av.count(c)) av.erase(c);
  }
  //cout << q << " " << av.size() << endl;
  if(av.size() > q) return false;
  for(char & c : s){
    if(c == '?'){
      if(av.size() > 0){
        c = *av.begin();
        av.erase(av.begin());
      }
      else c = 'A';
    }
  }
  for(int i=st, j = 0; j < s.size(); i++, j++) t[i] = s[j];
  for(char & c : t) if(c == '?') c = 'A';
  cout << t << endl;
  return true;
}
    
int32_t main(){
  DESYNC;
  string s;
  cin >> s;
  int n = s.size();
  for(int i=0; i<=n-26; i++){
    if(check(s.substr(i, 26), s, i)) return 0;
  }
  cout << -1 << endl;
}
 
