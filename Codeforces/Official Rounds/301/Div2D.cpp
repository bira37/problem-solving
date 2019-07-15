#include <bits/stdc++.h>

using namespace std;

struct info{
  double r,p,s;
  info(){}
  info(double r, double p, double s) : r(r), p(p), s(s) {}
};

info dp[101][101][101];

info solve(int r, int p, int s){
  if(r < 0 || p < 0 || s < 0) return info(0,0,0);
  if(r == 0 && p == 0 && s == 0) return info(1,1,1);
  if(r > 0 && p == 0 && s == 0) return info(1, 0, 0);
  if(r == 0 && p > 0 && s == 0) return info(0, 1, 0);
  if(r == 0 && p == 0 && s > 0) return info(0, 0, 1);
  
  if(dp[r][p][s].r >= 0) return dp[r][p][s];
  
  int tot = r*p + r*s + p*s;
  dp[r][p][s].r = ((r*p*solve(r-1,p,s).r) + (r*s*solve(r, p, s-1).r) + (p*s*solve(r, p-1, s).r))/tot;
  dp[r][p][s].p = ((r*p*solve(r-1,p,s).p) + (r*s*solve(r, p, s-1).p) + (p*s*solve(r, p-1, s).p))/tot;
  dp[r][p][s].s = ((r*p*solve(r-1,p,s).s) + (r*s*solve(r, p, s-1).s) + (p*s*solve(r, p-1, s).s))/tot;
  return dp[r][p][s];
}

int main(){
  int r,p,s;
  cin >> r >> s >> p;
  for(int i=0; i<=r; i++){
    for(int j=0; j<=p; j++){
      for(int k=0; k<=s; k++){
        dp[i][j][k] = info(-1,-1,-1);
      }
    }
  }
  cout << fixed << setprecision(15);
  info ans = solve(r,p,s);
  cout << ans.r << " " << ans.s << " " << ans.p << endl;
}