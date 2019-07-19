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
  int n, q;
  cin >> n >> q;
  set<int> app[n+1];
  deque < ii > ntf;
  
  int unread = 0;
  int max_read = 0;
  for(int i=0; i<q; i++){
    int t,x;
    cin >> t >> x;
    if(t == 1){
      app[x].insert(i);
      ntf.push_back(ii(x, i));
      unread++;
    }
    else if(t == 2){
      unread -= app[x].size();
      app[x].clear();
    }
    else {
      //cout << x << " " << ntf.size() << endl;
      int y = x;
      x -= max_read;
      if(x < 0) x = 0;
      while(x--){
        auto news = ntf.front();
        if(app[news.ff].count(news.ss)){
          app[news.ff].erase(news.ss);
          unread--;
        }
        ntf.pop_front();
      }
      max_read = max(max_read, y);
    }
    cout << unread << endl;
  }
}
      
  
