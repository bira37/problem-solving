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
 
int dist[(1<<20)];
 
struct info{
  bitset<20> valid;
  int st;
  int d;
};
 
int32_t main(){
  DESYNC;
  int n, k;
  cin >> n >> k;
  for(int i=0; i<(1<<k); i++) dist[i] = 1123456789;
  int v[n];
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    v[i] = 0;
    for(int b=0; b<k; b++){
      if(s[b] == '1') v[i] |= (1<<b);
    }
  }
  queue< info > q;
  for(int i=0; i<n; i++){
    info cur;
    cur.st = v[i];
    dist[v[i]] = 0;
    cur.d = 0;
    for(int b=0; b<k; b++) cur.valid[b] = true;
    q.push(cur);
  }
  while(!q.empty()){
    info cur = q.front();
    int state = cur.st;
    int d = cur.d;
    bitset<20> valid = cur.valid;
    q.pop();
    for(int i=0; i<k; i++){
      if(!valid[i]) continue;
      int new_state = state^(1<<i);
      if(dist[new_state] <= d + 1) continue;
      info aux;
      aux.st = new_state;
      aux.valid = valid;
      aux.valid[i] = false;
      aux.d = d+1;
      dist[new_state] = d+1;
      q.push(aux);
    }
  }
  int mx = -1;
  int ans = -1;
  for(int i=0; i<(1<<k); i++){
    if(mx < dist[i]){
      mx = dist[i];
      ans = i;
    }
  }
  string ret;
  for(int i=0; i<k; i++){
    if((1<<i) & ans) ret += '1';
    else ret += '0';
  }
  reverse(ret.begin(), ret.end());
  cout << ret << endl;
}
 
