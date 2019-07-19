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
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  vector< set<int> > v(n);
  for(int i=0; i<n; i++){
    int k;
    cin >> k;
    while(k--){
      int x;
      cin >> x;
      v[i].insert(x);
    }
  }
  
  for(int i=0; i<n; i++){
    bool ok = true;
    for(int j=0; j<n; j++){
      if(i == j) continue;
      
      int cnt = 0;
      for(int x : v[i]) cnt += v[j].count(x);
      ok &= !(cnt == v[j].size());
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}
