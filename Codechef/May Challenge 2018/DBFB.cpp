#include <bits/stdc++.h>
#define int long long
using namespace std;

inline void mod(int & n){
  n = n%1000000007LL;
}

int32_t main(){
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> m >> n;
    int a[m];
    int b[m];
    for(int i=0; i<m; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    
    if(n < 3){
      int suma = 0;
      int sumb = 0;
      
      for(int i=0; i<m; i++){
        suma += a[i];
        mod(suma);
      }
      for(int i=0; i<m; i++){
        sumb += b[i];
        mod(sumb);
      }
      if(n == 1){
        int inter = m;
        mod(inter);
        int ans = suma*inter;
        mod(ans);
        cout << ans << endl;
      }
      else {
        int inter = m;
        mod(inter);
        int ans = sumb*inter;
        mod(ans);
        cout << ans << endl;
      }
    }
    
    else {
      
      int l2 = 1, l1 = 1;
      for(int i=3; i<n; i++){
        int novo = l1+l2;
        l2 = l1;
        l1 = novo;
        mod(l1);
        mod(l2);
      }
      
      int suma = 0;
      int sumb = 0;
      
      for(int i=0; i<m; i++){
        suma += a[i];
        mod(suma);
      }
      //cout << suma << " " << l2 << " " << l1 << endl;
      int ans = 0;
      for(int i=0; i<m; i++){
        int ans1 = m;
        mod(ans1);
        ans1 = ans1*b[i];
        mod(ans1);
        ans1 = ans1*l1;
        mod(ans1);
        ans += ans1;
        mod(ans);
        int inter = suma;
        mod(inter);
        inter = inter*l2;
        mod(inter);
        ans += inter;
        mod(ans);
      }
      cout << ans%1000000007 << endl;
    }
  }
}
      
