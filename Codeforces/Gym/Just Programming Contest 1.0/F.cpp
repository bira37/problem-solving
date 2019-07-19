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
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
void read_int(int* p) {
  static char c;
  while ((c = getchar()) < '0'); // just to be safe
  for (*p = c-'0'; (c = getchar()) >= '0'; *p = *p*10+c-'0');
}
 
int32_t main(){
  //DESYNC;
	int t;
  read_int(&t);
  while(t--){
    int n,m,q;
    read_int(&n);
    read_int(&m);
    read_int(&q);
    int mat[501][n+1][m+1];
    int integral[501][n+1][m+1];
    int pref[501][n+1][m+1];
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        pref[0][i][j] = 0;
        for(int k = 0; k<=500; k++) mat[k][i][j] = 0;
        int x;
        read_int(&x);
        mat[x][i][j] = 1;
      }
    }
    for(int num = 0; num <= 500; num++){
      for(int i=0; i<=m; i++){
        mat[num][0][i] = 0;
        integral[num][0][i] = 0;
        pref[num][0][i] = 0;
      }
      for(int i=0; i<=n; i++){
        mat[num][i][0] = 0;
        integral[num][i][0] = 0;
        pref[num][i][0] = 0;
      }
    }
    for(int num = 0; num <= 500; num++){ 
      for(int i=1; i<=n; i++){
        int acc = 0;
        for(int j =1; j<=m; j++){
          acc += mat[num][i][j];
          integral[num][i][j] = integral[num][i-1][j] + acc;
          if(num >= 1) pref[num][i][j] = pref[num-1][i][j] + integral[num][i][j];
          else pref[0][i][j] = 0;
        }
      }
    }
 
    
    while(q--){
      int l1,r1,l2,r2;
      read_int(&l1);
      read_int(&r1);
      read_int(&l2);
      read_int(&r2);
      int qtd = (r2 - r1 + 1)*(l2 - l1 + 1);
      qtd = qtd/2 + (qtd%2);
      
      int ans = -1;
      int l = 1, r = 500;
      
      while(l <= r){
        int mid = (l+r)>>1;
        int val = pref[mid][l2][r2] + pref[mid][l1-1][r1-1] - pref[mid][l2][r1-1] - pref[mid][l1-1][r2];
        if(val >= qtd){
          ans = mid;
          r = mid-1;
        }
        else l = mid+1;
      }
      printf("%lld\n", ans);
    }
  }
}
