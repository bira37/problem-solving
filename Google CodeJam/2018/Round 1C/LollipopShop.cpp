#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    set<int> flavor;
    for(int i=1; i<=n; i++) flavor.insert(i);
    int interest[n+1];
    for(int i=1; i<=n; i++) interest[i] = 0;
    for(int i=0; i<n; i++){
      int d;
      cin >> d;
      int has = -1;
      for(int j=0; j<d; j++){
        int x;
        cin >> x;
        interest[x]++;
        if(flavor.count(x)){
          if(has == -1){
            has = x;
          }
          else if(interest[x] < interest[has]){
            has = x;
          }
        }
      }
      if(has != -1) flavor.erase(has);
      cout << has << endl;
      cout.flush();
    }
  }
}
          
