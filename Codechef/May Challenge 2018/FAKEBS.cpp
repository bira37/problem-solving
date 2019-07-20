#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    map<int,int> val, pos;
    int n, q;
    cin >> n >> q;
    int v[n+1];
    int a[n+1];
    for(int i=1; i<=n; i++){
      cin >> a[i];
      v[i] = a[i];
    }
    sort(a+1, a+n+1);
    for(int i=1; i<=n; i++){
      val[a[i]] = i;
    }
    for(int i=1; i<=n; i++){
      v[i] = val[v[i]];
      pos[v[i]] = i;
    }
    
    while(q--){
      int x;
      cin >> x;
      x = val[x];
      
      int want = pos[x];
      
      //cout << "want " << x << ", " << want << endl;
      
      vector<int> list;
      int l = 1, r = n;
      while(l <= r){
        int m = (l+r)/2;
        if(m == want) break;
        else if(m < want){
          l = m+1;
          list.push_back(m);
        }
        else {
          r  = m-1;
          list.push_back(m);
        }
      }
      int menor = x-1;
      int maior = n - x;
      //cout << "menor e maior " << menor << " " << maior << endl;
      int errL = 0, errR = 0;
      for(int m : list){
        if(m < want){
          if(v[m] > x) errL++;
          else {
            menor--;
          }
        }
        else if(m > want){
          if(v[m] < x) errR++;
          else {
            maior--;
          }
        }
      }
      //cout << "maior " << maior << " / menor " << menor << " / errL " << errL << " / errR " << errR << endl;
      if(errL <= menor && errR <= maior){
        cout << min(errL, errR) + max(errL, errR) - min(errL, errR) << '\n';
      }
      else cout << -1 << '\n';
      
    } 
  }
}
