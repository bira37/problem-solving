#include <bits/stdc++.h>
#define int long long
using namespace std;

map< pair<int,int>, int> freq;
int32_t main(){
  int n;
  cin >> n;
  vector< pair<int,int> > s;
  map<int,int> mx, my;
  int ans = 0;
  for(int i=0; i<n; i++){
    int x,y;
    cin >> x >> y;
    ans -= freq[make_pair(x,y)];
    ans += mx[x];
    ans += my[y];
    mx[x]++;
    my[y]++;
    freq[make_pair(x,y)]++;
  }
  
  cout <<ans << endl;
}  

