#include <bits/stdc++.h>
#define int long long
using namespace std;

int dpl[512345];
int dpr[512345];
int n, a , b, t;

bool check(int m){
  //cout << "checking " << m << endl;
  if(dpl[m-1] <= t) return true;
  if(dpr[m-1] <= t) return true;
  m--;
  for(int i=1; i<=m-1; i++){
    //cout << i  << " on left and " << m-i << " on right " << endl;
    if(i < (m-i)){
      int curr = dpl[i];
      curr += (i)*a;
      curr += (dpr[m-i] - dpr[0]);
      //cout << curr << endl;
      if(curr <= t) return true;
    }
    else {
      int curr = dpr[m-i];
      curr += (m-i)*a;
      curr += (dpl[i] - dpl[0]);
      //cout << curr << endl;
      if(curr <= t) return true;
    }
  }
    
  return false;
}
  
int32_t main(){
  
  cin >> n >> a >> b >> t;
  vector<int> v;
  for(int i=0; i<n; i++){
    char c;
    cin >> c;
    if(c == 'w') v.push_back(1 + b);
    else v.push_back(1);
  }
  for(int i=0; i<n; i++){
    v.push_back(v[i]);
  }
  //for(int x : v) cout << x << " ";
  //cout << endl;
  dpl[0] = v[n];
  dpr[0] = v[n];
  if(dpl[0] > t){
    cout << 0 << endl;
    return 0;
  }
 // cout << "zero is " << dpl[0] << endl;
  for(int i=n+1; i<2*n; i++){
    dpr[i-n] = dpr[i-n-1] + a + v[i];
    //cout << "dpr of " << i-n << " equals to " << dpr[i-n] << endl;
  }
  for(int i=n-1, it = 1; i>0; i--, it++){
    dpl[it] = dpl[it-1] + a + v[i];
    //cout << "dpl of " << it << " equals to " << dpl[it] << endl;
  }
  
  int l = 0, r = n;
  int ans = 0;
  while(l <= r){
    int m = (l+r)/2;
    if(check(m)){
      ans = m;
      l = m+1;
    }
    else r = m-1;
  }
  
  cout << ans << endl;
}