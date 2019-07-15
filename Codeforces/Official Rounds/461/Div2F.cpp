#include <bits/stdc++.h>

using namespace std;

int contrib[312345] = {0};
bool in_set[312345] = {0};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> ans;
  int cnt = 0;
  for(int i=1; i<=n/2; i++){
    if(cnt + contrib[i] <= k){
      ans.push_back(i);
      in_set[i] = true;
      cnt += contrib[i];
      for(int j = i+i; j <= n; j+=i) contrib[j]++;
    }
    else {
      while(cnt + contrib[i] > k){
        cnt -= contrib[ans.back()];
        for(int j = ans.back()+ans.back(); j <= n; j+=ans.back()) contrib[j]--;
        in_set[ans.back()] = false;
        ans.pop_back();
      }
      ans.push_back(i);
      in_set[i] = true;
      cnt += contrib[i];
      for(int j = i+i; j <= n; j+=i) contrib[j]++;
    }
    if(cnt == k) break;
  }
  //cout << cnt << endl;
  priority_queue< pair<int, int> >  pq;
  for(int i= n/2+1; i<=n; i++){
    if(in_set[i]) continue;
    pq.push(make_pair(contrib[i], i));
  }
  while(!pq.empty()){
    while(!pq.empty() && cnt + pq.top().first > k) pq.pop();
    if(pq.empty()) break;
    cnt += pq.top().first;
    ans.push_back(pq.top().second);
    pq.pop();
  }
  //cout << cnt << endl;
  if(cnt != k){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  cout << ans.size() << endl;
  for(int i=0; i<ans.size(); i++){
    if(i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}