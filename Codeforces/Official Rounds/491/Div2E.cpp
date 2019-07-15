#include <bits/stdc++.h>

using namespace std;

#define int long long

int fat[30];

vector<int> cnt(10);

map< vector<int> , bool > vis;

int calc(vector<int> cnt){
  int ans = 0;
  for(int i = 1; i<10; i++){
    if(cnt[i] == 0) continue;
    bool eita = false;
    cnt[i]--;
    int sz = 0;
    for(int j = 0; j<10; j++) sz += cnt[j];
    int cur = fat[sz];
    for(int j=0; j<10; j++) cur /= fat[cnt[j]];
    cnt[i]++;
    ans += cur;
  }
  return ans;
}

int solve(vector<int> cnt){
  vis[cnt] = true;
  int ans = calc(cnt);
  vector<int> cnt2 = cnt;
  for(int i=0; i<10; i++){
    if(cnt2[i] <= 1) continue;
    cnt2[i]--;
    if(!vis[cnt2]) ans += solve(cnt2);
    cnt2[i]++;
  }
  return ans;
}
    
int32_t main(){
  string s;
  for(int i=0; i<10; i++) cnt[i] = 0;
  fat[0] = 1;
  for(int i=1; i<29; i++) fat[i] = fat[i-1]*i;
  cin >> s;
  for(char c : s){
    cnt[c - '0']++;
  }
  cout << solve(cnt) << endl;
}
  