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
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int s;
    cin >> s;
    int dst[s+100][7];
    for(int i=0; i<=s+99; i++){
      for(int j=0; j<=6; j++) dst[i][j] = INF;
    }
    queue< tuple<int,int, int> > q;
    q.push(mt(0, 1, 0));
    dst[0][1] = 0;
    while(!q.empty()){
      int sum, dice, rolls;
      tie(sum, dice, rolls) = q.front();
      q.pop();
      if(sum >= s) continue;
      if(dst[sum][dice] < rolls) continue;
      if(dice == 1 || dice == 6){
        if(dst[sum+2][2] > rolls+1){
          dst[sum+2][2] = rolls+1;
          q.push(mt(sum+2, 2, rolls+1));
        }
        if(dst[sum+3][3] > rolls+1){
          dst[sum+3][3] = rolls+1;
          q.push(mt(sum+3, 3, rolls+1));
        } 
        if(dst[sum+4][4] > rolls+1){
          dst[sum+4][4] = rolls+1;
          q.push(mt(sum+4, 4, rolls+1));
        } 
        if(dst[sum+5][5] > rolls+1){
          dst[sum+5][5] = rolls+1;
          q.push(mt(sum+5, 5, rolls+1));
        }
      }
      else if(dice == 2){
        if(dst[sum+1][1] > rolls+1){
          dst[sum+1][1] = rolls+1;
          q.push(mt(sum+1, 1, rolls+1));
        }
        if(dst[sum+3][3] > rolls+1){
          dst[sum+3][3] = rolls+1;
          q.push(mt(sum+3, 3, rolls+1));
        } 
        if(dst[sum+4][4] > rolls+1){
          dst[sum+4][4] = rolls+1;
          q.push(mt(sum+4, 4, rolls+1));
        } 
        if(dst[sum+6][6] > rolls+1){
          dst[sum+6][6] = rolls+1;
          q.push(mt(sum+6, 6, rolls+1));
        }
      }
      else if(dice == 3  || dice == 4){
        if(dst[sum+1][1] > rolls+1){
          dst[sum+1][1] = rolls+1;
          q.push(mt(sum+1, 1, rolls+1));
        }
        if(dst[sum+2][2] > rolls+1){
          dst[sum+2][2] = rolls+1;
          q.push(mt(sum+2, 2, rolls+1));
        } 
        if(dst[sum+5][5] > rolls+1){
          dst[sum+5][5] = rolls+1;
          q.push(mt(sum+5, 5, rolls+1));
        } 
        if(dst[sum+6][6] > rolls+1){
          dst[sum+6][6] = rolls+1;
          q.push(mt(sum+6, 6, rolls+1));
        }
      }
      else if(dice == 5){
        if(dst[sum+1][1] > rolls+1){
          dst[sum+1][1] = rolls+1;
          q.push(mt(sum+1, 1, rolls+1));
        }
        if(dst[sum+3][3] > rolls+1){
          dst[sum+3][3] = rolls+1;
          q.push(mt(sum+3, 3, rolls+1));
        } 
        if(dst[sum+4][4] > rolls+1){
          dst[sum+4][4] = rolls+1;
          q.push(mt(sum+4, 4, rolls+1));
        } 
        if(dst[sum+6][6] > rolls+1){
          dst[sum+6][6] = rolls+1;
          q.push(mt(sum+6, 6, rolls+1));
        }
      }
    }
    int ans = INF;
    for(int i=1; i<=6; i++) ans = min(ans, dst[s][i]);
    if(ans < INF) cout << ans << endl;
    else cout << -1 << endl;
  }
    
}
 
