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

struct snake{
  int a,b,c,d;
};

void solve(){
  int n,m;
  cin >> n >> m;
  char mat[n][m];
  snake s[26];
  for(int i=0; i<26; i++){
    s[i].a = s[i].b = INF;
    s[i].c = s[i].d = -INF;
  }
  set<char> qtd;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
    char c;
    cin >> c;
    mat[i][j] = c;
    if(c == '.') continue;
    qtd.insert(c);
    s[c-'a'].a = min(s[c-'a'].a, i);
    s[c-'a'].b = min(s[c-'a'].b, j);
    s[c-'a'].c = max(s[c-'a'].c, i);
    s[c-'a'].d = max(s[c-'a'].d, j);
    }
  }

  vector< tuple<int,int,int,int> > ans;
  vector<int> idx_ans;
  for(int k=0; k<26; k++){
    if(s[k].a == INF) continue;
    for(int i=s[k].a; i<=s[k].c; i++){
      for(int j=s[k].b; j<=s[k].d; j++){
        if(mat[i][j]-'a' < k || mat[i][j] == '.'){
        cout << "NO" << endl;
        return;
        }
      }
    }
    ans.pb(make_tuple(s[k].a, s[k].b, s[k].c, s[k].d));
    idx_ans.pb(k);
  }

  for(int i=0; i<26; i++){
    if(s[i].a == INF) continue;
    if(s[i].a != s[i].c && s[i].b != s[i].d){
    cout << "NO" << endl;
    return;
  }
}

  cout << "YES" << endl;
  if(ans.size() == 0){
    cout << 0 << endl;
    return;
  }
  vector< tuple<int,int,int,int> > real_ans;
  int lst = -1;
  for(int i=0; i<ans.size(); i++){
  //cout << lst+1 << " " << idx_ans[i] << endl;
    for(int x = lst+1; x <= idx_ans[i]; x++){
      real_ans.pb(ans[i]);
    }
    lst = idx_ans[i];
  }
  cout << real_ans.size() << endl;
  for(auto tp : real_ans){
    int a,b,c,d;
    tie(a,b,c,d) = tp;
    cout << a+1 << " " << b+1 << " " << c+1 << " " << d+1 << endl;
  }
}

int32_t main(){
DESYNC;
int t;
cin >> t;
while(t--) solve();
}