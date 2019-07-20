#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
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
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
int32_t main(){
  //DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n,s,e;
    cin >> n >> s >> e;
    int dist[n];
    string v[n];
    vector<int> g[n];
    for(int i=0; i<n; i++){
      dist[i] = INF;
      cin >> v[i];
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        int cnt1[10];
        int cnt2[10];
        for(int i=0; i<10; i++) cnt1[i] = cnt2[i] = 0;
        for(char c : v[i]){
          cnt1[c - '0']++;
        }
        for(char c : v[j]){
          cnt2[c - '0']++;
        }
        int acc = 0;
        for(int i=0; i<10; i++) acc += min(cnt1[i], cnt2[i]);
        if(acc == 17){
          g[i].pb(j);
        }
      }
    }
    s--,e--;
    dist[s] = 0;
    queue< tuple<int,int> > q;
    q.push(mt(s, dist[s]));
    while(!q.empty()){
      int dst, cur;
      tie(cur, dst) = q.front();
      q.pop();
      if(dist[cur] < dst) continue;
      for(int w : g[cur]){
        if(dist[w] > dst + 1){
          dist[w] = dst+1;
          q.push(mt(w, dist[w]));
        }
      }
    }
    if(dist[e] < INF) cout << dist[e] << endl;
    else cout << -1 << endl;
  }
}
 
