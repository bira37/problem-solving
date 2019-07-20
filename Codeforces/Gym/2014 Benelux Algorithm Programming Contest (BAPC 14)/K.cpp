#include <bits/stdc++.h>
 
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
 
int check(string a, string b){
  int match = 0;
  for(int i=0; i<a.size(); i++){
    if(a[i] == b[i])match++;
  }
  return match;
} 
 
string convert(int x, int sz){
  string s;
  for(int i = sz-1; i>=0;  i--){
    if((1<<i) & x) s += '1';
    else s += '0';
  }
  return s;
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    vector<int> cor(n);
    vector<string> l(n), r(n);
    vector< vector<int> > cntl((1<<(m/2)), vector<int>(n)), cntr((1<<(m - m/2)), vector<int>(n));
    for(int i=0; i<n; i++){
      string s;
      cin >> s >> cor[i];
      int x = 0;
      for(int j = 0; j<m/2; j++) l[i] += s[j];
      for(int j=m/2; j<m; j++) r[i] += s[j];
    }
    
    vector<int> lef, rig;
    
    for(int msk = 0; msk < (1<<(m/2)); msk++){
      bool ok = true;
      string s = convert(msk, m/2);
      for(int i=0; i<n && ok; i++){
        cntl[msk][i] = cor[i] - (check(l[i], s));
        if(cntl[msk][i] < 0) ok = false;
      }
      if(ok) lef.pb(msk);
    }
    
    for(int msk = 0; msk  < (1<<(m - m/2)); msk++){
      string s = convert(msk, m - m/2);
      bool ok = true;
      for(int i=0; i<n && ok; i++){
        cntr[msk][i] = (check(r[i], s));
        if(cntr[msk][i] > cor[i]) ok = false; 
      }
      if(ok) rig.pb(msk);
    }
    
    sort(lef.begin(), lef.end(), [&cntl](const int & a, const int & b){
      return cntl[a] < cntl[b];
    });
    
    sort(rig.begin(), rig.end(), [&cntr](const int & a, const int & b){
      return cntr[a] < cntr[b];
    });
    
    int ans = 0;
    string bst = "";
    
    int puta1 = 0, puta2 = 0;
    while(puta1 < lef.size() && puta2 < rig.size()){
      int bazinga = 1;
      while(puta1 + 1 < lef.size() && cntl[lef[puta1]] == cntl[lef[puta1+1]]){
        puta1++;
        bazinga++;
      }
      while(puta2 < rig.size() && cntl[lef[puta1]] > cntr[rig[puta2]]) puta2++;
      while(puta2 < rig.size() && cntl[lef[puta1]] == cntr[rig[puta2]]){
        ans += bazinga;
        if(ans == 1){
          bst = convert(lef[puta1], m/2) + convert(rig[puta2], m - m/2);
        }
        puta2++;
      }
      puta1++;
    }
     
    if(ans == 1) cout << bst << endl;
    else cout << ans << " solutions" << endl;
  }  
}
