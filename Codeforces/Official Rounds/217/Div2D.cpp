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
 
char mat[2123][2123];
int n,m;
int cnt = 0; 
bool check(int xl, int yl, int s){
  if(xl < 0 || yl < 0 || xl + s - 1 >= n || yl + s -1 >= m){
    return false;
  }
  int conta = 0;
  for(int i=xl; i<xl+s; i++){
    for(int j = yl; j < yl+s; j++){
      if((i == xl || j == yl || i == xl+s-1 || j == yl + s -1) && mat[i][j] == 'w') conta++;
    }
  }
  return conta == cnt;
}
 
void print_ans(int xl, int yl, int s){
  for(int i=xl; i<xl+s; i++){
    for(int j = yl; j < yl+s; j++){
      if(i == xl || j == yl || i == xl+s-1 || j == yl + s -1){
        if(mat[i][j] != 'w') mat[i][j] = '+';
      }
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout << mat[i][j];
    }
    cout << endl;
  }
}
 
int32_t main(){
  DESYNC;
  cin >> n >> m;
  int max_x = -1, min_x = 5000, max_y = -1, min_y = 5000;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> mat[i][j];
      if(mat[i][j] == 'w'){
        cnt++;
        max_x = max(max_x, i);
        min_x = min(min_x, i);
        max_y = max(max_y, j);
        min_y = min(min_y, j);
      }
    }
  }
  int s = max(max_x-min_x+1, max_y-min_y+1);
  vector<int> xs,ys;
  xs.pb(0); xs.pb(min_x); xs.pb(max_x-s+1);
  ys.pb(0); ys.pb(min_y); ys.pb(max_y-s+1);
  
  for(int a : xs){
    for(int b : ys){
      if(check(a,b,s)){
        print_ans(a,b,s);
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
  
