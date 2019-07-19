#include <bits/stdc++.h>
 
#define int long long
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
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int ans = 0;
 
int32_t main(){
  DESYNC;
  string s;
  cin >> s;
  int n = s.size();
  set<string> ss;
  for(int i=0; i<n; i++){
    for(int c = 0; c<26; c++){
      string t = s.substr(0, i);
      t += (c+'a');
      t += s.substr(i, n - i);
      ss.insert(t);
    }
  }
  for(int c = 0; c < 26; c++){
    string t = s;
    t += c+'a';
    ss.insert(t);
  }
  cout << ss.size() << endl;
}
