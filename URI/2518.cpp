#include <bits/stdc++.h>

using namespace std;

int main() {
  double n;
  while(cin >> n){
    double h,c,l;
    cin >> h >> c >> l;
    double hip = sqrt(c*c+h*h);
    cout << fixed << setprecision(4) << (hip*l*n)/10000. << endl;
  }
}
