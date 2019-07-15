#include <bits/stdc++.h>
 
#define int long long
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
int32_t main(){
	DESYNC;
	int n, t;
	cin >> n >> t;
	int a[n+1];
	int bet[n+1];
	for(int i=0; i<n; i++) cin >> a[i];
	a[n] = t;
	int on[n+1];
	int off[n+1];
  int lst = 0;
  for(int i=0; i<=n; i++){
    bet[i] = a[i] - lst;
    lst = a[i];
    if(i%2 == 0){
      on[i] = (i - 1 >= 0 ? on[i-1] : 0);
      on[i] += bet[i];
      off[i] = (i - 1 >= 0 ? off[i-1] : 0);
    }
    else {
      off[i] = (i - 1 >= 0 ? off[i-1] : 0);
      off[i] += bet[i];
      on[i] = (i - 1 >= 0 ? on[i-1] : 0);
    }
  }
  int ans = on[n];
  lst = 0;
  for(int i=0; i<=n; i++){
    //cout << "range " << lst << " " << a[i] << endl;
    if(i%2 == 0){
      //cout << "mod 0 " << endl;
      if(lst+1 < a[i]){
        //cout << "try putting at " << lst+1 << endl;
        int cur = 1 + (off[n] - off[i]) + (i - 1 >= 0 ? on[i-1] : 0);
        //cout << "cur " << cur << endl;
        ans = max(ans, cur);
      }
      if(a[i]-1 > lst){
        //cout << "try putting at " << a[i]-1 << endl;
        int cur = ((a[i]-1) - lst) + (off[n] - off[i]) + (i - 1 >= 0 ? on[i-1] : 0);
        //cout << "cur " << cur << endl;
        ans = max(ans, cur);
      }
      lst = a[i];
    }
    else {
      //cout << "mod 1 " << endl;
      if(lst+1 < a[i]){
        //cout << "try putting at " << lst+1 << endl;
        int cur = a[i] - (lst + 1) + (off[n] - off[i]) + (i - 1 >= 0 ? on[i-1] : 0);
        //cout << "cur " << cur << endl;
        ans = max(ans, cur);
      }
      if(a[i]-1 > lst){
        //cout << "try putting at " << a[i]-1 << endl;
        int cur = 1 + (off[n] - off[i]) + (i - 1 >= 0 ? on[i-1] : 0);
       // cout << "cur " << cur << endl;
        ans = max(ans, cur);
      }
      lst = a[i];
    }
  }
  //for(int i=0; i<=n; i++){
  //  cout << i << " " << on[i] << " " << off[i] << endl;
 // }
	cout << ans << endl;
}
