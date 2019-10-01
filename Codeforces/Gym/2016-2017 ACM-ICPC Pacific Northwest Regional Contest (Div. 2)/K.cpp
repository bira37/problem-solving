#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int a[6], b[6];
  for(int i=0; i<6; i++) cin >> a[i];
  for(int i=0; i<6; i++) cin >> b[i];
  
  int den = 36;
  int num = 0;
  for(int i=0; i<6; i++){
    for(int j=0; j<6; j++){
      if(a[i] > b[j]) num++;
      if(a[i] == b[j]) den--;
    }
  }
  
  cout << fixed << setprecision(5) << double(num)/double(den) << endl;
}
