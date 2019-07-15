#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<string> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  map<string, int> index;
  map<string, set<int> > cnt;
  for(int i=0; i<n; i++){
    for(int a =0; a < v[i].size(); a++){
      string cur = "";
      for(int b =a; b<v[i].size(); b++){
        cur += v[i][b];
        index[cur] = i;
        cnt[cur].insert(i);
      }
    }
  }
  int q;
  cin >> q;
  while(q--){
    string s;
    cin >> s;
    if(cnt[s].size() > 0) cout << cnt[s].size() << " " << v[index[s]] << endl;
    else cout << cnt[s].size() << " -" << endl;
  }
} 