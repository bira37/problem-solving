#include <bits/stdc++.h>
 
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
 
struct shelf{
  vector<bool> s;
  int qtd = 0;
  shelf(){}
  shelf(int m){
    s = vector<bool>(m, false);
  }
};
 
 
int32_t main(){
  DESYNC;
  int n, m, q;
  cin >> n >> m >> q;
  vector< vector<shelf*> > st;
  vector< shelf* > cur;
  for(int i=0; i<n; i++){
    cur.pb(new shelf(m));
  }
  st.pb(cur);
  vector<int> vec_ans;
  vec_ans.pb(0);
  int ans = 0;
  while(q--){
    cur = st.back();
    int op;
    cin >> op;
    if(op == 1){
      int i,j;
      cin >> i >> j;
      i--, j--;
      shelf * dummy = new shelf(m);
      for(int j=0; j<m; j++){
        dummy->s[j] = cur[i]->s[j];
      }
      dummy->qtd = cur[i]->qtd;
      if(!dummy->s[j]){
        dummy->qtd++;
        ans++;
      }
      dummy->s[j] = true;
      cur[i] = dummy;
      st.pb(cur);
    }
    else if(op == 2){
      int i,j;
      cin >> i >> j;
      i--, j--;
      shelf * dummy = new shelf(m);
      for(int j=0; j<m; j++){
        dummy->s[j] = cur[i]->s[j];
      }
      dummy->qtd = cur[i]->qtd;
      if(dummy->s[j]){
        dummy->qtd--;
        ans--;
      }
      dummy->s[j] = false;
      cur[i] = dummy;
      st.pb(cur);
    }
    else if(op == 3){
      int i;
      cin >> i;
      i--;
      shelf * dummy = new shelf(m);
      for(int j=0; j<m; j++){
        dummy->s[j] = cur[i]->s[j];
      }
      dummy->qtd = cur[i]->qtd;
      for(int j=0; j<dummy->s.size(); j++){
        if(dummy->s[j]){
          dummy->qtd--;
          ans--;
          dummy->s[j] = false;
        }
        else if(!dummy->s[j]){
          dummy->qtd++;
          ans++;
          dummy->s[j] = true;
        }
      }
      cur[i] = dummy;
      st.pb(cur);
    }
    else{
      int x;
      cin >> x;
      st.pb(st[x]);
      ans = vec_ans[x];
    }
    /*cout << "op " << st.size() - 1 << endl;
    for(int i=0; i<st.back().size(); i++){
      for(int j=0; j<st.back()[i]->s.size(); j++){
        cout << st.back()[i]->s[j] << " ";
      }
      cout << endl;
    }
    cout << endl;*/
    vec_ans.pb(ans);
    cout << ans << endl;
  }
}
  
 
