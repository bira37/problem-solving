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

int exp(int a, int k){
  if(a == 1) return 1LL;
  if(k == 1) return a;
  int aux = exp(a, k/2);
  aux = mod(aux*aux, M);
  if(k%2) aux = mod(aux*a, M);
  return aux;
}

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    double s = 0;
    int v[n];
    for(int i=0; i<n; i++){
      cin >>v[i];
      s += v[i];
    }
    int ans = INF;
    for(int i=0; i<n; i++){
      double art = s/(double)n;
      double art2 = (s-(v[i]))/(double)(n-1);
      if(abs(art-art2) <= 1e-10){
        ans = min(ans, i+1);
      }
    }
    cout << (ans == INF ? "Impossible" : to_string(ans)) << endl;
  }
}


