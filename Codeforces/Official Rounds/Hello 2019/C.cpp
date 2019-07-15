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

int pref[512345], suf[512345];

ii judge(string s){
  int cur = 0;
  bool bad = false;
  for(char c : s){
    if(c == '(') cur++;
    else cur--;
    if(cur < 0) bad = true;
  }
  if(!bad && cur == 0) return ii(0,0);
  if(!bad) return ii(1, cur);
  
  bad = false;
  reverse(s.begin(), s.end());
  for(char & c : s){
    if(c == '(') c = ')';
    else c = '(';
  }
  cur = 0;
  for(char c : s){
    if(c == '(') cur++;
    else cur--;
    if(cur < 0) bad = true;
  }
  if(bad) return ii(-1, 0);
  else return ii(2, cur);
}
    
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int cor = 0;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    ii get = judge(s);
    if(get.ff == 0) cor++;
    else if(get.ff == 1) pref[get.ss]++;
    else if(get.ff == 2) suf[get.ss]++;
  }
  int ans = cor/2;
  for(int i=1; i<=512345; i++) ans += min(pref[i], suf[i]);
  cout << ans << endl;   
}

