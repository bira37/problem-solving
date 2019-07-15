#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  
  int m;
  cin >> m;
  
  int v[n];
  for(int i=0; i<n; i++) cin >>v[i];
  
  int maxx = 0;
  for(int i=0; i<n; i++) maxx = max(maxx, v[i] +m);
  
  int minx = 0;
  
  while(m--){
    int menor = 1e9;
    int best = -1;
    for(int i=0; i<n; i++){
      if(menor > v[i]){
        menor = v[i];
        best = i;
      }
    }
    v[best]++;
  }
  
  for(int i=0; i<n; i++) minx = max(minx, v[i]);
  
  cout << minx << " " << maxx << endl;
}