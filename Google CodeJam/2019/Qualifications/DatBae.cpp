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

bool solve(){
  int n,b,f;
  cin >> n >> b >> f;
  
  //first query
  string s;
  for(int i=0; i<n; i+=16){
    for(int j=i; j<n && j < i+16; j++) s += ((i/16)%2 ? '1' : '0');
  }
  cout << s << endl;
  cout.flush();
  cin >> s;
  f--;
  vector<int> working;
  //analize buckets
  int ptr = 0;
  bool want = 0;
  int cnt = 0;
  for(int i=0; i<n; i+=16){
    while(ptr < n && s[ptr] == '0' + want){
      ptr++;
      cnt++;
    }
    working.pb(cnt);
    cnt = 0;
    want = !want;
  }
  int bucket = 8; 
  while(bucket > 0){
    string s;
    for(int i=0; i<n; i+=bucket){
      for(int j=i; j<n && j < i+bucket; j++) s += ((i/bucket)%2 ? '1' : '0');
    }
    cout << s << endl;
    cout.flush();
    cin >> s;
    f--;
    int acc = 0;
    vector<int> new_working;
    for(int sz : working){
      string cur = s.substr(acc, sz);
      acc += sz;
      int qtd0 = 0, qtd1 = 0;
      for(char c : cur){
        if(c == '0') qtd0++;
        else qtd1++;
      }
      new_working.pb(qtd0);
      new_working.pb(qtd1);
    }
    working.clear();
    for(int x : new_working){
      working.pb(x);
    }
    new_working.clear();
    bucket/=2;
  }
  vector<int> ans;
  for(int i=0; i<n; i++){
    if(working[i] == 0) ans.pb(i);
  }
  string t;
  for(int i=0; i<ans.size(); i++){
    if(i > 0) t += ' ';
    t += to_string(ans[i]);
  }
  cout << t << endl;
  cout.flush();
  int verdict;
  cin >> verdict;
  if(verdict == 1) return true;
  return false;
}

int32_t main(){
  int t;
  cin >> t;
  for(int i=1; i<=t; i++){
    if(!solve()) return 0;
  }
}


