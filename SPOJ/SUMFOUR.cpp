#include <bits/stdc++.h>

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  if(n == 0){
    cout << 0 << endl;
    return 0;
  }
  vector<int> A(n),B(n),C(n),D(n);
  for(int i=0; i<n; i++){
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }
  vector<int> v;
  for(int x : A){
    for(int y : B){
      v.push_back(x+y);
    }
  }
  sort(v.begin(), v.end());
  vector< pair<int,int> > Cordeiro, Lucas;
  Cordeiro.push_back(pair<int,int>(v[0], 1));
  for(int i=1; i<v.size(); i++){
  	if(v[i] == Cordeiro.back().first) Cordeiro.back().second++;
  	else Cordeiro.push_back(pair<int,int>(v[i], 1));
  }
  v.clear();
  for(int x : C){
    for(int y : D){
      v.push_back(x+y);
    }
  }
  sort(v.begin(), v.end());
  Lucas.push_back(pair<int,int>(v[0], 1));
  for(int i=1; i<v.size(); i++){
  	if(v[i] == Lucas.back().first) Lucas.back().second++;
  	else Lucas.push_back(pair<int,int>(v[i], 1));
  }
  long long res = 0;
  for(pair<int,int> x : Cordeiro){
    int qtd = x.second;
    int num = -x.first;
    int l = 0, r=Lucas.size()-1, ans = -1;
    while(l <= r){
      int m = (l+r)>>1;
      if(Lucas[m].first > num){
        r = m-1;
      }
      else if(Lucas[m].first < num) l = m+1;
      else {
        ans = m;
        break;
      }
    } 
    if(ans == -1) continue;
    res += qtd*Lucas[ans].second;
  }
  cout << res << endl;
}
