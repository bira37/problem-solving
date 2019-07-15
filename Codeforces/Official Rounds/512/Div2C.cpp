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
  int n;
  cin >> n;
  string s;
  cin >> s;
  //corner
  int sum = 0;
  for(char c : s){
    sum += c-'0';
  }
  int zeros = 0;
  for(int i=0; i<n; i++){
    if(s[i] == '0') zeros++;
  }
  if(zeros == n){
    cout << "YES" << endl;
    return 0;
  }
  for(int i=1; i<sum; i++){
    bool ok = true;
    int cur = 0;
    int p = 0;
    for(; p<s.size(); p++){
      cur += s[p] - '0';
      if(cur > i){
        ok = false;
        break;
      }
      else if(cur < i){
        continue;
      }
      else if(cur == i){
        cur = 0;
      }
    }
    if(cur == 0 && ok){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}

