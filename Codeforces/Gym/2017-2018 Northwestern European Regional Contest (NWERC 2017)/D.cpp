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
 
map<string, int> correct;
map<string, int> tot;
map<string, string> translate;
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  vector<string> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  int m;
  cin >> m;
  for(int i=0; i<m; i++){
    string a,b,c;
    cin >> a >> b >> c;
    translate[a] = b;
    if(c == "correct") correct[a]++;
    tot[a]++;
  }
  int all_ans = 1;
  int correct_ans = 1;
  for(string s : v){
    correct_ans *= correct[s];
    all_ans *= tot[s];
  }
  if(all_ans == 1){
    for(string s : v) cout << translate[s] << " ";
    cout << endl;
    if(correct_ans == 1) cout << "correct" << endl;
    else cout << "incorrect" << endl;
  }
  else {
    cout << correct_ans << " correct" << endl;
    cout << all_ans - correct_ans << " incorrect" << endl;
  }
}
 
