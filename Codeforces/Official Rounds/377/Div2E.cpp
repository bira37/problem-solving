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
  vector<ii> p,s;
  int n,m;
  cin >> n >> m;
  vector<bool> pu(n, false), su(m, false);
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    p.pb(ii(x, i));
  }
  for(int i=0; i<m; i++){
    int x;
    cin >> x;
    s.pb(ii(x,i));
  }
  
  sort(p.begin(), p.end());
  sort(s.begin(), s.end());
  vector<ii> ans;
  int qtd = 0;
  int match = 0;
  vector<int> ansc(n, 0);
  vector<int> ansa(m, 0);
  
  for(int iter=0; iter<=32; iter++){
    
    //match all unused
    int cur = 0;
    for(int i=0; i<n; i++){
      if(pu[p[i].ss]) continue;
      while(cur < m && (su[s[cur].ss] || s[cur].ff < p[i].ff)) cur++;
      if(cur >= m) continue;
      if(s[cur].ff != p[i].ff) continue;
      //matching 
      //cout << "match " << p[i].ff << "  with " << s[cur].ff << " on " << iter << endl;
      ansa[s[cur].ss] = iter;
      ansc[p[i].ss] = s[cur].ss+1;
      match++;
      su[s[cur].ss] = true;
      pu[p[i].ss] = true;
      qtd += iter;
    }
    
    for(int i=0; i<m; i++) s[i].ff = (s[i].ff + 1)/2;
  }
  
  cout << match << " " << qtd << endl;
  for(int i=0; i<m; i++) cout << ansa[i] << " ";
  cout << endl;
  for(int i=0; i<n; i++) cout << ansc[i] << " ";
  cout << endl;
  
}
 
