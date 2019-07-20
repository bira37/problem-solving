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
  string s;
  cin >> s;
  int cur = 0;
  deque<int> q;
  vector<int> opened;
  for(int i =0; i<s.size(); i++){
    if(s[i] == '?') q.push_back(i);
    else if(s[i] == '('){
      cur++;
      opened.pb(i);
    }
    else {
      if(cur == 0 && q.size() == 0){
        cout << "Impossible" << endl;
        return 0;
      }
      else if(cur == 0){
        s[q.front()] = '(';
        q.pop_front();
      }
      else {
        opened.pop_back();
        cur--;
      }
    }
  }
  while(cur > 0){
    if(q.size() == 0){
      cout << "Impossible" << endl;
      return 0;
    }
    if(q.back() < opened.back()){
      cout << "Impossible" << endl;
      return 0;
    }
    s[q.back()] = ')';
    q.pop_back();
    opened.pop_back();
    cur--;
  }
  if(q.size()%2 == 1){
    cout << "Impossible" << endl;
    return 0;
  }
  else {
    char cur = '(';
    char last = ')';
    while(!q.empty()){
      s[q.front()] = cur;
      q.pop_front();
      swap(cur, last);
    }
    cout << s << endl;
  }
}
 
