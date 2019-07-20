#include <bits/stdc++.h>
 
#define int long long
#define ff first
#define ss second
#define endl '\n'
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define EPS 1e-9
#define INF (int)1e18
#define ROOT 1
 
using namespace std;
 
inline int mod(int n){ return n%1000000007; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
int conv(string s){
  int ans = 0;
  for(char c : s){
    ans = 10*ans + (c-'0');
  }
  return ans;
}
 
string derivative(string s){
  string ans;
  bool nox = true;
  for(char c : s) if(c == 'x') nox = false;
  if(nox) return ans;
  if(s.size() == 1){
    if(s[0] == 'x'){
      ans += '1';
      return ans;
    }
    else return ans;
  }
  
  string num1, num2;
  int p = 0;
  while(p < s.size() && s[p] != 'x') num1 += s[p++];
  p++;
  while(p < s.size() && s[p] != 'x') num2 += s[p++];
  if(num2.size() == 0) num2 += '1';
  if(num1.size() == 0) num1 += '1';
  ans += to_string(conv(num1)*conv(num2));
  ans += 'x';
  if(conv(num2) - 1 > 1) ans += to_string(conv(num2)-1);
  else if(conv(num2) -1 == 0) ans.pop_back();
  return ans;
}
 
int32_t main(){
  DESYNC;
  
  string s;
  cin >> s;
  vector<char> op;
  vector<string> num;
  
  int p =0;
  bool type;
  if(s[p] == '-' || s[p] == '+'){
    op.pb(s[p++]);
    type = true;
  }
  else type = true;
  
  while(p < s.size()){
    while(p < s.size() && s[p] == ' ') p++;
    if(!type){
      op.pb(s[p++]);
      type = true;
    }
    else {
      string t;
      while(p < s.size() && s[p] != '-' && s[p] != '+' && s[p] != ' ') t += s[p++];
      if(t.size() > 0) num.pb(t);
      type = false;
    }
  }
  
  vector<string> der;
  for(string n : num) der.pb(derivative(n));
  string ans;
  if(der.size() == op.size()){
    for(int i=0; i<der.size(); i++){
      ans += op[i];
      ans += der[i];
    }
  }
  else {
    ans += der[0];
    for(int i=0; i<op.size(); i++){
      ans += op[i];
      ans += der[i+1];
    }
  }
  while(ans.size() > 0 && (ans.back() == '-' || ans.back() == '+' || ans.back() == ' ')) ans.pop_back();
  if(ans.size() == 0) ans += '0';
  cout << ans << endl;
}
