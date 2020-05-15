#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  while(getline(cin,s)){
    bool valid = true, l = false, u = false, n = false;
    for(int i=0; i<s.size(); i++){
      if(s[i] >= 'a' && s[i] <= 'z') l = true;
      else if(s[i] >= 'A' && s[i] <= 'Z') u = true;
      else if(s[i] >= '0' && s[i] <= '9' ) n = true;
      else valid = false;
    }
    valid = valid & l & u & n;
    if(s.size() < 6 || s.size() > 32) valid = false;
    if(valid) cout << "Senha valida." << endl;
    else cout << "Senha invalida." << endl;
  }
}
