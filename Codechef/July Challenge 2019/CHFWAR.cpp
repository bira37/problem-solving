#include <bits/stdc++.h>
#define INF (int)1e18
#define int long long
using namespace std;

int n;
int A[1123456];

int solve(int J, bool parity){
  int pot2 = 1;
  int attacker_right = n; //(parity ? n-1 : n);
  int attacker_left = J-1; //(parity ? J-2 : J-1);
  int left = J-1;
  int right = n-J+1;
  int shield = 0;
  while(left > 0 || right > 1){
    //cout << "with " << left << " and " << right << " soldiers" << endl;
    //cout << "and " << attacker_left << "[" << A[attacker_left] << "]" << " and " << attacker_right << "[" << A[attacker_right] << "]" << endl << endl;
    if(left > 0 && left%2 == 1) shield += A[attacker_left];
    if(left > 0){
      if(left%2 == 0) attacker_left -= pot2;
      int tira = left/2;
      left -= tira;
    }
    if(right > 0 && right%2 == 1){
      if(left > 0) left--;
      else shield += A[attacker_right];
    }
    if(right%2 == 0) attacker_right -= pot2;
    int tira = right/2;
    right -= tira;
    pot2 *= 2;
  }
  return shield;
}

void solve(){
  cin >> n;
  n--;
  for(int i=1; i<=n; i++) cin >> A[i];
  int f;
  cin >> f;
  int ans = INF;
  int bst = -1;
  for(int i=1; i<=n; i++){
    if(A[i] > f) continue;
    int got = solve(i, i%2);
    if(got < ans){
      ans = got;
      bst = i;
    }
  }
  if(ans == INF){
    cout << "impossible" << endl;
  }
  else{
    cout << "possible" << endl;
    cout << bst << " " << ans+f << endl;
  }
}
  
int32_t main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--) solve();
}
