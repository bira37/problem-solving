#include <bits/stdc++.h>

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

int v[212345];

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  deque< ii > dq;
  int id = 0;
  int i = 0;
  while(id < n){
    bool found = false;
    if(i - id >= 2*n){
      for(int i=0; i<n; i++) cout << -1 << " ";
      cout << endl;
      return 0;
    }
    if(dq.size() > 0){
      if(v[i%n]*2 < dq.front().ff){
        cout << i - id << " ";
        if(dq.front().ss == id) dq.pop_front();
        id++;
        found = true;
      }
      else {
        while(dq.size() > 0 and dq.back().ff < v[i%n]) dq.pop_back();
      }
    }
    //cout << i << " " << found<< endl;
    if(!found) dq.push_back(ii(v[i%n], i));
    if(!found) i++;
  }
  cout << endl;
}

 
