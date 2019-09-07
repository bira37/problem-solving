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
  //DESYNC;
  int n;
  cin >> n;
  int m = (1LL<<n);
  multiset<int, greater<int> > need;
  for(int i=0; i<m; i++){
    int x;
    cin >> x;
    need.insert(x);
  }
  multiset<int, greater<int> > slimes;
  slimes.insert(*need.begin());
  need.erase(need.begin());
  while(slimes.size() < m){
    //cout << "here" << endl;
    vector<int> add;
    for(int x : slimes){
      auto it = need.upper_bound(x);
      if(it == need.end()){
        cout << "No" << endl;
        return 0;
      }
      //cout << "adding " << *it << endl;
      add.pb(*it);
      need.erase(it);
    }
    for(int x : add) slimes.insert(x);
  }
  if(need.size() == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

  
    
}


