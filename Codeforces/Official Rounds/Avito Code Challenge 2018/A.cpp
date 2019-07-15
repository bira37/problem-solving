#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  string t  = s;
  reverse(t.begin(), t.end());
  if(s != t){
    cout << s.size() << endl;
    return 0;
  }
  s.pop_back();
  t  = s;
  reverse(t.begin(), t.end());
  if(s != t){
    cout << s.size() << endl;
    return 0;
  }
  
  cout << 0 << endl;
}