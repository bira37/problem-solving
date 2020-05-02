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

struct node{
  map<char, node*> adj;
  int cnt = 0;
  node(){
    cnt = 0;
  }
};

void insert(node * root, string s){
  node * cur = root;
  for(int i=0; i<s.size(); i++){
    if(!cur->adj.count(s[i])) cur->adj[s[i]] = new node();
    cur = cur->adj[s[i]];
    cur->cnt++;
  } 
}

int go(node * cur, int & ans){
  int rem = 0;
  for(auto child : cur->adj){
    rem += go(child.ss, ans);
  }
  //cout << cur->cnt << " " << rem << endl;
  if(cur->cnt - rem >= 2){
    ans += 2;
    rem += 2;
  }
  return rem;
}

void solve(int test){
  cout << "Case #" << test << ": ";
  int n;
  cin >> n;
  node *root = new node();
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    insert(root, s);
  }
  int ans = 0;
  go(root, ans);  
  cout << ans << endl;
}

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  for(int i=1; i<=t; i++) solve(i);
}


