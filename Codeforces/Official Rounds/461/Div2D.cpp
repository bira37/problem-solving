#include <bits/stdc++.h>
#define int long long
using namespace std;

struct sh{
  string s;
  int cs=0,ch=0;
};

bool cmp(const sh & a, const sh & b){
  return a.cs*b.ch > b.cs*a.ch;
}

int32_t main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  sh v[n];
  for(int i=0; i<n; i++){
    cin >> v[i].s;
    for(char c : v[i].s){
      if(c == 's') v[i].cs++;
      else v[i].ch++;
    }
  }
  sort(v, v+n, cmp);
  int cnt = 0;
  long long ans = 0;
  string total = "";
  for(int i=0; i<n; i++) total += v[i].s;
  for(char c : total){
    if(c == 's') cnt++;
    else ans += cnt;
  }
  cout << ans << endl;
}