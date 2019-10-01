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
 
int n;
char mat[105][105];
 
void go(int i, int j, char ch){
  mat[i][j] = ch;
  char newch;
  if(ch == 'W') newch = 'B';
  else newch = 'W'; 
  if(i+1 < n and j+2 < n and mat[i+1][j+2] == 'Z') go(i+1, j+2, newch);
  if(i-1 >= 0 and j+2 < n and mat[i-1][j+2] == 'Z') go(i-1, j+2, newch);
  if(i+1 < n and j-2 >= 0 and mat[i+1][j-2] == 'Z') go(i+1, j-2, newch);
  if(i-1 >= 0 and j-2 >= 0 and mat[i-1][j-2] == 'Z') go(i-1, j-2, newch);
  if(i+2 < n and j+1 < n and mat[i+2][j+1] == 'Z') go(i+2, j+1, newch);
  if(i-2 >= 0 and j+1 < n and mat[i-2][j+1] == 'Z') go(i-2, j+1, newch);
  if(i+2 < n and j-1 >= 0 and mat[i+2][j-1] == 'Z') go(i+2, j-1, newch);
  if(i-2 >= 0 and j-1 >= 0 and mat[i-2][j-1] == 'Z') go(i-2, j-1, newch);  
}
 
int32_t main(){
  DESYNC;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) mat[i][j] = 'Z';
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) if(mat[i][j] == 'Z') go(i,j, 'W');
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) cout << mat[i][j];
    cout << endl;
  }
}
