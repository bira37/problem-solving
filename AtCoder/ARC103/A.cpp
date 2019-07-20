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
  map<int,int> even, odd;
  int e = 0, o =0;
  for(int i=0; i<n; i++){
    int x;
    cin >>x;
    if(i%2 == 0){
      e++;
      even[x]++;
    }
    else{
      o++;
      odd[x]++;
    }
  }
  set< ii > ev, od;
  for(auto it : even){
    ev.insert(ii(e - it.ss, it.ff));
  }
  for(auto it : odd){
    od.insert(ii(o - it.ss, it.ff));
  }
  if(ev.begin()->ss != od.begin()->ss){
    cout << ev.begin()->ff + od.begin()->ff <<endl;
  }
  else {
    if(ev.size() == 1){
      cout << od.begin()->ff + e << endl;
    }
    else if(od.size() == 1){
      cout << ev.begin()->ff + o << endl;
    }
    else {
      int ans1 = ev.begin()->ff;
      int ans2 = od.begin()->ff;
      ev.erase(ev.begin());
      od.erase(od.begin());
      ans1 += od.begin()->ff;
      ans2 += ev.begin()->ff;
      cout << min(ans1,ans2) << endl;
    }
  }
}


