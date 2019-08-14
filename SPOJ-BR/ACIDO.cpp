#include <bits/stdc++.h>

using namespace std;

int main(){
  string x;
  while(cin >> x){
    int n = x.size();
    stack<char> s;
    int ans = 0;
    for(int i=0; i<n; i++){
      if(s.empty()){
        s.push(x[i]);
      }
      else {
        if(x[i] == 'S' && s.top() == 'B' || x[i] == 'B' && s.top() == 'S') s.pop(),ans++;
        else if(x[i] == 'C' && s.top() == 'F' || x[i] == 'F' && s.top() == 'C') s.pop(),ans++;
        else s.push(x[i]);
      }
    }
    cout << ans << endl;
  }
}
