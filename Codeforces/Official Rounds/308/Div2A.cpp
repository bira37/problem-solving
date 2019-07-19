#include <bits/stdc++.h>
#define int long long
using namespace std;
int mat[100][100] = {0};
int32_t main(){
  int n;
  cin >> n;
  while(n--){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--,b--,c--,d--;
    for(int i=a; i<=c; i++){
      for(int j=b; j <= d; j++) mat[i][j]++;
    }
  }
  int ans = 0;
  for(int i=0; i<100; i++){
    for(int j=0; j<100; j++){
      ans += mat[i][j];
    }
  }
  cout << ans << endl;
} 
