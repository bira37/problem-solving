#include <iostream>
#include <map>
#include <vector>
#define int long long
using namespace std;
  
int32_t main(){
  int n;
  map<int,int> m;
  cin >> n;
  int v[n];
  for(int i=0; i<n; i++) cin >> v[i];
  int sum = 0;
  int ans = 0;
  m[0]++;
  for(int i=0; i<n; i++){
    sum += v[i];
    ans += m[sum];
    m[sum]++;
  }
  cout << ans << endl;
}
