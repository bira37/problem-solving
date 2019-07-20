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
 
string s;
 
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
 
void up(int *cr, int *cc, int *cd, char m) {
  if(m == 'R') {
    (*cd)++;
    (*cd)%=4;
  } else if(m == 'L'){
    (*cd)--;
    if((*cd) < 0) (*cd)+=4;
  } else if(m == 'B') {
    (*cd)-=2;
    if((*cd) < 0) (*cd)+=4;
  }
  (*cr) += dr[(*cd)];
  (*cc) += dc[(*cd)];
}
 
string G[210];
 
 
int mir, mar, mic, mac;
 
void dfs(int r, int c, int d, int i) {
 
  //cout << r << "  " << c << endl;
  //cout << d << " " << dr[d] << " " << dc[d] << endl;
  //cout << s[i] << endl;
  //cout << endl;
  G[r][c] = '.';
  if(i == s.size()) return;
  mir = min(mir, r);
  mar = max(mar, r);  
  mic = min(mic, c);
  mac = max(mac, c);
  up(&r, &c, &d, s[i]);
  dfs(r,c,d,i+1);
}
 
 
int32_t main(){
  DESYNC;
  
  int T;
  cin >> T;
  cout << T << endl;
  
  for(int i = 0; i < 210; i++) {
    G[i].resize(210);
  }
  
  for(int t = 0; t < T; t++) {
 
    for(int i = 0; i < 210; i++) {
      for(int j = 0; j < 210; j++) {
        G[i][j] = '#';
      }
    }
 
    cin >> s;
    //cout << s << endl;
    mir = 250;
    mar = -1;
    mic = 250;
    mac = -1;
 
    dfs(105,105,0,0);
            //cout << t << endl;
    int w = mac-mic+1+1;
    int h = mar-mir+1+2;
    cout <<  h << " " << w << endl;
 
   // cout << mir << " " << mar << endl;
    for(int i = 0; i < 210; i++) {
      if(i >= mir-1 && i <= mar+1) {
        cout << G[i].substr(mic, w) << endl;
      }
    }
    //cout << endl << endl;
  }
}
 
