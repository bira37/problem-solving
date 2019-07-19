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
 
int vis[112345];
int sum[112345];
int last[112345];
 
int32_t main(){
  DESYNC;
  
  for(int i=0; i<112345; i++){
    vis[i] = -1;
    sum[i] = 0;
    last[i] = -1;
  }
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    queue< ii > q;
    q.push(ii(x, 0));
    vis[x]++;
    sum[x] += 0;
    last[x] = i;
    while(!q.empty()){
      int val = q.front().ff;
      int op = q.front().ss;
      q.pop();
      //break the number
      if(last[val/2] < i){
        vis[val/2]++;
        last[val/2] = i;
        sum[val/2] += (op+1);
        q.push(ii(val/2, op+1));
      }
      
      //double the number
      if(val*2 < 112345 && last[val*2] < i){
        vis[val*2]++;
        sum[val*2] += (op+1);
        last[val*2] = i;
        q.push(ii(val*2, op+1));
      }
    }
  }
  int mx = INF;
  for(int i=0; i<112345; i++){
    if(vis[i] == n-1) mx = min(mx, sum[i]);
  }
  cout << mx << endl;
}
 
