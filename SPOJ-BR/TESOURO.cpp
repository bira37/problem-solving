#include <bits/stdc++.h>

#define int long long
#define double long double
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
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

int32_t main(){
  DESYNC;
  int n,m, k;
  int t = 1;
loop:  while(cin >> n >> m >> k, n+m+k != 0){
    cout << "Teste " << t++ << endl;
    int s = 0;
    bitset<10001> dp, aux;
    dp.reset();
    aux.reset();
    dp.set(0);
    for(int i=0; i<k; i++){
      int x;
      cin >> x;
      s += x;
      aux |= dp;
      aux <<= x;
      dp |= aux;
    }
    int ss1 = m + s - n;
    int ss2 = n + s - m;
    if(ss1 >= 0 && ss1%2 == 0 && dp[ss1/2]){
      cout << "S" << endl << endl;
      goto loop;
    }
    else if(ss2 >=0 && ss2%2 == 0 && dp[ss2/2]){
      cout << "S" << endl << endl;
      goto loop;
    }
    else {
      cout << "N" << endl << endl;
      goto loop;
    }
  }
}


