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
  int cnt1 = 0;
  int cnt2 = 0;
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    if(x == 1) cnt1++;
    else cnt2++;
  }
  if(cnt1 >= 3){
    cnt1 -= 3;
    cout << "1 1 1 ";
  }
  else if(cnt1 >= 1 && cnt2 >= 1){
    cnt1--;
    cnt2--;
    cout << "2 1 ";
  }
  while(cnt2 > 0){
    cout << "2 ";
    cnt2--;
  }
  while(cnt1 > 0){
    cout << "1 ";
    cnt1--;
  }
  cout << endl; 
}

