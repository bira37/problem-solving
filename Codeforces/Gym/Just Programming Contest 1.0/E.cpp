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
    int n,d,x;
    cin >> n >> d >> x;
    int best_dist = INF;
    int best_coin = INF;
    int best_idx = INF;
    for(int i=0; i<n; i++){
      int dist, coin;
      cin >> dist >> coin;
      if(dist > d) continue;
      if(dist < best_dist && coin >= x){
        best_dist = dist;
        best_idx = i+1;
        best_coin = coin;
      }
      else if(dist == best_dist){
        if(coin > best_coin){
          best_dist = dist;
          best_idx = i+1;
          best_coin = coin;
        }
      }
    }
    cout << (best_idx != INF ? best_idx : -1) << endl;
  }
}
