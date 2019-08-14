#include <bits/stdc++.h>

using namespace std;

int main(){
  double x,y,z1,z2;
  while(cin >> x >> y, x+y != 0){
    double deltasqrt = sqrt(16*(x+y)*(x+y) - 48*x*y);
    z1 = 4*(x+y) + deltasqrt;
    z2 = 4*(x+y) - deltasqrt;
    z1/=24;
    z2/=24;
    cout << fixed << setprecision(4);
    if(-4*x -4*y + 24*z1 < 0) cout << z1 << " " << (x-2*z1)*(y - 2*z1)*z1 << endl;
    else cout << z2 << " " << (x-2*z2)*(y-2*z2)*z2 << endl;
  }
}
