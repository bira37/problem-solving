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
 
bool check(int n){
  string s = to_string(n);
  int mid = s.size()/2;
  string n1 = s.substr(0, mid + (s.size()%2));
  string n2 = s.substr(mid+(s.size()%2), mid);
  int x1 = conv(n1);
  int x2 = conv(n2);
  if(gcd(x1, x2) == 1) return true;
  else return false;
}
 
int32_t main(){
  DESYNC;
	int t;
  cin >> t;
  while(t--){
    int l,r;
    cin >> l >> r;
    bool ok = false;
    for(int i=r; i>=l; i--){
      if(check(i)){
        cout << i << endl;
        ok = true;
        break;
      }
    }
    if(!ok) cout << -1 << endl;
  }
}
