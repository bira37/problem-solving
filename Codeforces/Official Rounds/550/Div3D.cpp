#include <bits/stdc++.h>

#define int long long
#define double long double
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
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}


int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int ans = INF;
  map<int, int> m;
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
    m[v[i]]++;
  }
  int number = -1;
  for(int i=0; i<n; i++){
      if(n - m[v[i]] < ans){
        number = v[i];
        ans = min(ans, n - m[v[i]]);
      }
  }
  cout << ans << endl;
  vector<string> prt;
  queue<int> q;
  for(int i=0; i<n; i++) if(v[i] == number) q.push(i);
  while(!q.empty()){
      int u = q.front();
      q.pop();
      if(u-1 >= 0 && v[u-1] != number){
          if(v[u-1] > v[u]) prt.pb("2 " + to_string(u) + " " + to_string(u+1));
          else prt.pb("1 " + to_string(u) + " " + to_string(u+1));
          v[u-1] = number;
          q.push(u-1);
      }
      if(u+1 < n && v[u+1] != number){
         if(v[u+1] > v[u]) prt.pb("2 " + to_string(u+2) + " " + to_string(u+1));
         else prt.pb("1 " + to_string(u+2) + " " + to_string(u+1));
         v[u+1] = number;
         q.push(u+1); 
      }
  }
  for(string s : prt) cout << s << endl;
}