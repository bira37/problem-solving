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

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  map<int,int> cat;
  cat[0] = -4;
  cat[1] = -1;
  cat[2] = -3;
  cat[3] = -2;
  map<int, char> cu;
  cu[-1] = 'A';
  cu[-2] = 'B';
  cu[0] = 'D';
  cu[-3] = 'C';
  int bst = cat[n%4];
  //cout << bst << endl;
  if(cat[(n+1)%4] > bst and cat[(n+1)%4] > cat[(n+2)%4]){
    cout << 1 << " " << cu[cat[(n+1)%4]] << endl;
  }
  if(cat[(n+1)%4] < bst and bst > cat[(n+2)%4]){
    cout << 0 << " " << cu[bst] << endl;
  }
  if(cat[(n+2)%4] > bst and cat[(n+2)%4] > cat[(n+1)%4]){
    cout << 2 << " " << cu[cat[(n+2)%4]] << endl;
  }
}

