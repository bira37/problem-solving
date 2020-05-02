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
  int tst;
  cin >> tst;
  for(int j=1; j<=tst; j++){
    string s;
    cin >> s;
    string t;
    for(char & c : s){
      if(c == '4'){
        c = '3';
        t += '1';
      }
      else t += '0';
    }
    reverse(t.begin(), t.end());
    while(t.size() > 0 && t.back() == '0') t.pop_back();
    reverse(t.begin(), t.end());
    if(t.size() == 0){
      for(int i=s.size()-1; i>=0; i--){
        if(s[i] == '0') s[i] = '9';
        else {
          if(s[i] == '5'){
            s[i] -= 2;
            t = "2";
          }
          else {
            s[i]--;
            t = "1";
          }
          break;
        }
      }
    }
    reverse(s.begin(), s.end());
    while(s.size() > 0 && s.back() == '0') s.pop_back();
    reverse(s.begin(), s.end());
    cout << "Case #" << j << ": " << s << " " << t << endl;  
  }
}


