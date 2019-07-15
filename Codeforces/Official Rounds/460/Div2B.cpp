#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int k;
  cin >> k;
  int cnt = 0;
  for(int i=10; i<=12000000; i++){
    int curr = 0;
    int aux = i;
    while(aux > 0){
      curr += aux%10;
      aux /=10;
    }
    if(curr == 10) cnt++;
    if(cnt == k){
      cout << i << endl;
      return 0;
    }
  }
}