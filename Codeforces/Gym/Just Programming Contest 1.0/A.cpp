#include <bits/stdc++.h>
#define M 1000000007
#define int long long
using namespace std;
 
int expo(int n, int k){
  if(k == 1) return n;
  int aux = expo(n, k/2);
  aux *= aux;
  aux %= M;
  if(k%2) aux *= n;
  aux %= M;
  return aux;
}
 
int fat[212345], inv[212345], pot[212345];
 
int32_t main(){
  fat[0] = 1;
  fat[1] = 1;
  inv[0] = 1;
  pot[0] = 1;
  for(int i=1; i<=212345; i++){
    fat[i] = fat[i-1]*i;
    fat[i] %= M;
    pot[i] = pot[i-1]*2;
    pot[i] %= M;
  }
  
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    n = abs(n);
    if(m-n < 0 || (m - n)%2 == 1){
      cout << 0 << endl;
    }
    else {
      int x = n + (m-n)/2;
      int ans = fat[m]*expo(fat[m-x], M-2);
      ans %= M;
      ans *= expo(fat[x], M-2);
      ans %= M;
      int dem = pot[m];
      dem = expo(dem, M-2);
      cout << (ans*dem)%M << endl;
    }
  }
} 
