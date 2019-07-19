#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
  int n;
  cin >> n;
  int d[] = {9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000};
  int ans = 0;
  if(n == 1000000000){
    for(int i=0; i<9; i++) ans += d[i]*(i+1);
    ans += 10;
  }
  else if(n >= 100000000){
    for(int i=0; i<8; i++) ans += d[i]*(i+1);
    ans += 9*(n - 100000000+1);
  }
  else if(n >= 10000000){
    for(int i=0; i<7; i++) ans += d[i]*(i+1);
    ans += 8*(n - 10000000+1);
  }
  else if(n >= 1000000){
    for(int i=0; i<6; i++) ans += d[i]*(i+1);
    ans += 7*(n - 1000000+1);
  }
  else if(n >= 100000){
    for(int i=0; i<5; i++) ans += d[i]*(i+1);
    ans += 6*(n - 100000+1);
  }
  else if(n >= 10000){
    for(int i=0; i<4; i++) ans += d[i]*(i+1);
    ans += 5*(n - 10000+1);
  }
  else if(n >= 1000){
    for(int i=0; i<3; i++) ans += d[i]*(i+1);
    ans += 4*(n - 1000+1);
  }
  else if(n >= 100){
    for(int i=0; i<2; i++) ans += d[i]*(i+1);
    ans += 3*(n - 100+1);
  }
  else if(n >= 10){
    for(int i=0; i<1; i++) ans += d[i]*(i+1);
    ans += 2*(n - 10+1);
  }
  else if(n >= 1){
    for(int i=0; i<0; i++) ans += d[i]*(i+1);
    ans += 1*(n - 1+1);
  }
  cout << ans << endl;
} 
