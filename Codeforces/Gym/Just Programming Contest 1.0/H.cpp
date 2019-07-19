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
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
int conv(string s){
  int acc = 0;
  for(char c : s){
    acc = 10LL*acc + (c-'0');
  }
  return acc;
}
 
int phi[1123456];
 
int32_t main(){
  DESYNC;
	int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int cnt = 0;
    int certow = s.size()/2 + (s.size()%2);
    int opo[s.size()];
    for(int l = 0, r = s.size()-1; l <= r; l++, r--){
      opo[l] = r;
      opo[r] = l;
    }
    for(int i=0; i<s.size()/2 + (s.size()%2); i++){
      if(s[i] == s[opo[i]]) cnt++;
    }
    int ans = 0;
    while(m--){
      int idx;
      char c;
      cin >> idx >> c;
      idx--;
      if(s[idx] == s[opo[idx]]) cnt--;
      s[idx] = c;
      if(s[idx] == s[opo[idx]]) cnt++;
      ans += (cnt == certow);
    }
    cout << ans << endl;
  }
}
