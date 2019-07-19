#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
  int n;
  cin >> n;
  int v[n];
  int maior = 0;
  for(int i=0; i<n; i++){
    cin >> v[i];
    maior = max(maior, v[i]);
  }
  int cont[maior+1];
  for(int i=0; i<=maior; i++) cont[i] = 0;
  for(int i=0; i<n; i++) cont[v[i]]++;
  int ans = 0;
  for(int i=1; i<=maior; i++){
    int curr = 0;
    for(int j=i; j<=maior; j+=i){
      curr += cont[j];
    }
    if(curr == 1) continue;
    ans = max(ans, curr*i);
  }
  cout << ans << endl;
}
