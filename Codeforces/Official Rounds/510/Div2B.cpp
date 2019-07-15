#include <bits/stdc++.h>
#define INF 1e8
#define pb push_back
#define ff first
#define ss second
using namespace std;

int main(){
  int n;
  cin >> n;
  int ma = INF, mb = INF, mc = INF;
  
  int triple = INF;
  vector< pair<string, int> > check;
  for(int i=0; i<n; i++){
    int p;
    cin >> p;
    string s;
    cin >> s;
    set<char> av;
    for(char c : s) av.insert(c);
    if(av.size() == 1){
      check.pb(make_pair(s, p));
      if(s == "A") ma = min(ma, p);
      else if(s == "B") mb = min(mb, p);
      else mc = min(mc, p);
    }
    else if(av.size() == 2){
      check.pb(make_pair(s, p));
    }
    else triple = min(triple, p);
  }
  int duo = INF;
  for(int i=0; i<check.size(); i++){
    for(int j=i+1; j<check.size(); j++){
      set<char> av;
      for(char c : check[i].ff) av.insert(c);
      for(char c : check[j].ff) av.insert(c);
      if(av.size() == 3) duo = min(duo, check[i].ss + check[j].ss);
    }
  }
  int ans = min({duo, triple, ma+mb+mc});
  cout << (ans >= 1e8 ? -1 : ans)  << endl;
}