#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  double ans = 10000000000000.00;
  for(int i=0; i<n; i++){
    int a, b;
    cin >> a >> b;
    ans = min(ans, m*(double)(a)/(double)(b));
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
}