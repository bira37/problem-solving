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
  int n,m;
  cin >> n >> m;
  priority_queue<int> pq;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    pq.push(-x);
  }
  vector<ii> cb;
  for(int i=0; i<m; i++){
    int b,c;
    cin >> b >> c;
    cb.pb(ii(-c,b));
  }
  sort(cb.begin(), cb.end());
  for(ii p : cb){
    int c = -p.ff;
    int b = p.ss;
    int cnt = 0;
    while(cnt < b){
      if(-pq.top() >= c){
        break;
      }
      cnt++;
      pq.pop();
      pq.push(-c);
    }
  }
  int ans = 0;
  while(pq.size() > 0){
    ans += pq.top();
    pq.pop();
  }
  cout << -ans << endl;
}


