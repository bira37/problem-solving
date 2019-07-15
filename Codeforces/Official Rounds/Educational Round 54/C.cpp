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
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  cout << fixed << setprecision(9) << endl;
loop:  while(t--){
    int d;
    cin >> d;
    int delt = d*d - 4*d;
    if(delt < 0){
      cout << "N" << endl;
      goto loop;
    }
    double x1 = (-d + sqrt(delt))/(-2.0);
    double x2 = (-d - sqrt(delt))/(-2.0);
    if(x1 >= 0 && d - x1 >= 0){
      cout << "Y" << " ";
      cout << abs(x1) << " " << abs(d-x1) << endl;
      goto loop;
    }
    if(x2 >= 0 && d - x2 >= 0){
      cout << "Y" << " ";
      cout << abs(x2) << " " << abs(d-x2) << endl;
      goto loop;
    }
    cout << "N" << endl;
  }   
}

