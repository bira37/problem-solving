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
#define EPS 1e-7
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
 
int convert(string s){
  int minus = 1;
  int num = 0;
  for(char c : s){
    if(c == '-'){
      minus = -1;
      continue;
    }
    num = num*10 + (c-'0');
  }
  return minus*num;
}
 
bool valid(string s){
  auto check = [&s](int pointer){
    return pointer < s.size();
  };
  
  string num1;
  char op;
  string num2;
  string equal;
  
  int pointer = 0;
  
  num1 += s[pointer];
  
  pointer++;
  while(check(pointer) && s[pointer] != '-' && s[pointer] != '*' && s[pointer] != '+') num1 += s[pointer++];
  
  op = s[pointer++];
  
  num2 += s[pointer++];
  
  while(check(pointer) && s[pointer] != '=') num2 += s[pointer++];
  
  pointer++;
  
  while(check(pointer)) equal += s[pointer++];
  
  if(num1.size() > 1 && num1[0] == '-' && num1[1] == '0') return false;
  if(num1.size() > 1 && num1[0] == '0') return false;
  if(num2.size() > 1 && num2[0] == '-' && num2[1] == '0') return false;
  if(num2.size() > 1 && num2[0] == '0') return false;
  if(equal.size() > 1 && equal[0] == '-' && equal[1] == '0') return false;
  if(equal.size() > 1 && equal[0] == '0') return false;
  
  int n1 = convert(num1);
  int n2 = convert(num2);
  int e = convert(equal);
  if(op == '+') return n1+n2 == e;
  else if(op == '-') return n1-n2 == e;
  else return n1*n2 == e;
}
 
int32_t main(){
  DESYNC;
  int t;
  cin>> t;
loop:  while(t--){
    string s;
    cin >> s;
    set<char> vis;
    for(char c : s) vis.insert(c);
    for(int d = '0'; d <= '9'; d++){
      if(vis.count(d)) continue;
      string t = s;
      for(char & c : t) if(c == '?') c = d;
      if(valid(t)){
        cout << char(d) << endl;
        goto loop;
      }
    }
    cout << -1 << endl;
  }
}
