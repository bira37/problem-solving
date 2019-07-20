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
 
int n, m;
string st;
string mp[51];
int sz;
 
  int ri, rj;
  int ei, ej;
 
int dp[51][51][51];
 
map<char, int> di;
map<char, int> dj;
 
bool good(int i, int j) {
  return (i>=0 && j>=0 && i < n && j < m);
}
 
set< tuple<int,int,int,int> > q;
 
int DP() { 
  q.insert(make_tuple(0, ri, rj, 0));
  dp[ri][rj][0] = 0;
  while(!q.empty()){
    int r,c,t,dist;
    tie(dist, r,c,t) = *q.begin();
    q.erase(q.begin());
    if(dist > dp[r][c][t]) continue;
    
    //cout << "at " << r << " " << c << " " << t << " " << dist << endl;
  
    if(t < st.size()) {
      int rr = r + di[st[t]];
      int cc = c + dj[st[t]];
      //cout << r << " " << c << endl;
      //cout << st[t] << endl;
      //cout << rr << " " << cc << endl; 
      // Use
      //cout << "Use" << endl;
      if(good(rr,cc) && mp[rr][cc] != '#') {
        //cout << "here" << endl;
        if(dp[rr][cc][t+1] > dist){
          dp[rr][cc][t+1] = dist;
          q.insert(make_tuple(dist, rr,cc,t+1));
        }
        
      } else if(dp[r][c][t+1] > dist){
        dp[r][c][t+1] = dist;
        q.insert(make_tuple(dist, r,c,t+1));
      }
      // Remove
      if(dp[r][c][t+1] > dist+1){
        dp[r][c][t+1] = dist+1;
        q.insert(make_tuple(dist+1, r,c,t+1));
      }
    }
    // Add
    string aux = "UDLR";
    for(char au : aux) {
      int rr = r + di[au];
      int cc = c + dj[au];
      if(good(rr, cc)) {
        if(mp[rr][cc] != '#') {
          if(dp[rr][cc][t] > dist+1){
            dp[rr][cc][t] = dist+1;
            q.insert(make_tuple(dist+1, rr,cc,t));
          }
        }
      }
    }
  }
  //cout << "dp[" << r << "][" << c << "][" << t << "] = " << dp[r][c][t] << endl;
  int ret = INT_MAX;
  for(int i=0; i<=st.size(); i++) ret = min(ret, dp[ei][ej][i]);
  return ret;
}
 
int32_t main(){
  DESYNC;
  
  di['U'] = -1;
  dj['U'] = 0;
  di['D'] = 1;
  dj['D'] = 0;
  
  di['R'] = 0;
  dj['R'] = 1;
  di['L'] = 0;
  dj['L'] = -1;  
  
  cin >> n >> m;
  
  for(int i = 0; i < n; i++) {
    cin >> mp[i];
    for(int j = 0; j < mp[i].size(); j++) {
      if(mp[i][j] == 'R') {
        ri = i;
        rj = j;
      }
      if(mp[i][j] == 'E') {
        ei = i;
        ej = j;
      }
    }
  }
  
  //cout << ri << " " << rj << endl;
  ///cout << ei << " " << ej << endl;  
  
  cin >> st;
  
  memset(dp, 0x3f3f3f3f, sizeof dp);
  
  cout << DP() << endl;
}
 
