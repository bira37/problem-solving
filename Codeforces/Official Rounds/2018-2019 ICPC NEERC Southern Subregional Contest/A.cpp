#include <bits/stdc++.h>

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
  int d,s;
  cin >> d >> s;
  queue< tuple<int,int,string> > q;
  bool vis[d+1][s+1];
  for(int i=0; i<=d; i++){
    for(int j=0; j<=s; j++){
      vis[i][j] = false;
    }
  }
  vis[0][0] = true;
  q.push(make_tuple(0,0,""));
  while(!q.empty()){
    int rem, sum;
    string cur;
    tie(rem, sum, cur) = q.front();
    q.pop();
    if(sum > s) continue;
    if(rem == 0 && sum == s){
      cout << cur << endl;
      return 0;
    }
    for(int i=0; i<=9; i++){
      int nxtrem = (10*rem + i)%d;
      int nxtsum = sum + i;
      if(vis[nxtrem][nxtsum] || nxtsum > s) continue;
      else {
        vis[nxtrem][nxtsum] = true;
        q.push(make_tuple(nxtrem, nxtsum, cur + to_string(i)));
      }
    }
  }
  cout << -1 << endl;
}

