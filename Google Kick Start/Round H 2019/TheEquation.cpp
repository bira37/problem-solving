#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

int solveBrute(int n, int m, int * v){
  int ans = -1;
  for(int k=0; k<=256; k++){
    int acc = 0;
    for(int i=0; i<n; i++) acc += (v[i]^k);
    if(acc <= m) ans = k;
  }
  return ans;
}

int solve(int n, int m, int * v){
  //get minimum ans

  int k = 0;
  for(int b = 52; b >= 0; b--){
    int cnt0 = 0, cnt1 = 0;
    for(int i=0; i<n; i++){
      if((1LL<<b) & v[i]) cnt1++;
      else cnt0++;
    }
    if(cnt1 > cnt0) k |= (1LL<<b);
  }

  //check if it fits m
  int acc = 0;
  for(int i=0; i<n; i++) acc += (v[i]^k);
  if(acc > m) return -1;

  //improve ans
  for(int b = 52; b >= 0; b--){
    if((1LL<<b) & k) continue;
    k |= (1LL<<b);
    int acc = 0;
    for(int i=0; i<n; i++) acc += (v[i]^k);
    if(acc > m) k ^= (1LL<<b);
  }

  return k;

}

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  //srand(time(NULL));
  for(int i=0; i<t; i++){
    //int n = 10, m = rand()%50 + 1;
    int n,m;
    cin >> n >> m;
    int v[n];
    for(int i=0; i<n; i++){
      cin >> v[i];
      //v[i] = rand()%16 + 1;
    }
    cout << "Case #" << i+1 << ": " << solve(n, m, v) << endl;
    /*if(solve(n,m,v) != solveBrute(n, m ,v)){
      cout << "ERROR" << endl;
      for(int i=0; i<n; i++) cout << v[i] << " ";
      cout << endl;
      break;
    }*/
  }
}



