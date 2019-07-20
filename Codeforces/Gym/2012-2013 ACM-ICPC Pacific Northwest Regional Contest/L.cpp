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
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int32_t main(){
  DESYNC;
  map<char,int> v,c;
  v['a'] = 0;
  v['i'] = 1;
  v['y'] = 2;
  v['e'] = 3;
  v['o'] = 4;
  v['u'] = 5;
  
  c['b'] = 0;
  c['k'] = 1;
  c['x'] = 2;
  c['z'] = 3;
  c['n'] = 4;
  c['h'] = 5;
  c['d'] = 6;
  c['c'] = 7;
  c['w'] = 8;
  c['g'] = 9;
  c['p'] = 10;
  c['v'] = 11;
  c['j'] = 12;
  c['q'] = 13;
  c['t'] = 14;
  c['s'] = 15;
  c['r'] = 16;
  c['l'] = 17;
  c['m'] = 18;
  c['f'] = 19;
  
  string s;
  while(getline(cin, s)){
    for(char ch : s){
      if(!(ch >= 'a' && ch <= 'z') && !(ch >= 'A' && ch <= 'Z')) cout << ch;
      else {
        int sum = 0;
        if(ch >= 'A' && ch <= 'Z'){
          sum = -32;
          ch += 32;
        }
        //cout << "char " << ch << endl;
        if(v.count(ch)){
          int val = (v[ch] + 3)%v.size();
          //cout << "val " << val << endl;
          for(auto p : v){
            if(p.ss == val) cout << char(p.ff + sum);
          }
        }
        else {
          int val = (c[ch] + 10)%c.size();
          for(auto p : c){
            if(p.ss == val) cout << char(p.ff + sum);
          }
        }
      }
    }
    cout << endl;
  }    
}
 
