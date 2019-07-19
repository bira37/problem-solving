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
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
bool solve(int n, int k){
  if(k < 4) return true;
  if(n == 1) return true;
  int cnt = 0;
  bool ans = false;
  if((n-1)%k == 0){
    cnt++;
    ans |= solve((n-1)/k, k);
  }
  if((n+1)%k == 0){
    cnt++;
    ans |= solve((n+1)/k, k);
  }
  if(n%k == 0){
    cnt++;
    ans |= solve(n/k, k);
  }
  if(cnt == 0) ans = false;
  return ans;
}
 
int32_t main(){
  DESYNC;
  int n,k;
  cin >> k >> n;
  if(solve(n,k)) cout << "YES" << endl;
  else cout << "NO" << endl;
} 
