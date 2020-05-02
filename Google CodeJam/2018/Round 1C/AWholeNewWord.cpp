#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int t;
  cin >> t;
  int caso = 1;
loop:  while(t--){
    cout << "Case #" << caso++ << ": ";
    int n, k;
    cin >> n >> k;
    set<string> s[k];
    set<char> use[k];
    vector<string> v(n);
    for(int i=0; i<n; i++){
      cin >> v[i];
      string t;
      for(int j=0; j<k; j++){
        t += v[i][j];
        s[j].insert(t);
        use[j].insert(v[i][j]);
      }
    }
    if(k == 1){
      cout << char(45) << endl;
      continue;
    }
    //trying to construct
    vector<string> ans;
    ans.push_back("");
    vector<bool> anything;
    anything.push_back(false);
    for(int i=0; i<k; i++){
      vector<string> to_push;
      vector<bool> anything_push;
      for(int x = 0; x < ans.size(); x++){
        if(anything[x]){
          ans[x] += *use[i].begin();
        }
        else {
          for(char c : use[i]){
            string test = ans[x];
            test += c;
            if(!s[i].count(test)){
              ans[x] += c;
              anything[x] = true;
              break;
            }
          }
          if(!anything[x]){
            for(char c : use[i]){
              if(c == *use[i].begin()) continue;
              string test = ans[x];
              test += c;
              to_push.push_back(test);
              anything_push.push_back(false);
            }
            ans[x] += *use[i].begin();
          }
        }
      }
      for(int x = 0; x < to_push.size(); x++){
        ans.push_back(to_push[x]);
        anything.push_back(anything_push[x]);
      }
    }
    for(int i=0; i<ans.size(); i++){
      if(anything[i]){
        cout << ans[i] << endl;
        goto loop;
      }
    }
    cout << char(45) << endl;
  }   
}
  
