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
  int q;
  cin >> q;
  while(q--){
    string s,t;
    int n;
    cin >> n;
    cin >> s >> t;
    vector< ii > swp;

    //brute this shit
    for(int i=0; i<n; i++){
      if(s[i] == t[i]) continue;
      //find the needed char
      int id = -1;
      for(int j=i+1; j<n; j++) if(t[j] == s[i]){
        id = j;
        break;
      }
      if(id != -1){
        //two swap
        swap(s[i+1], t[id]);
        swap(s[i+1], t[i]);
        swp.pb(ii(i+1, id));
        swp.pb(ii(i+1, i));
        continue;
      }
      for(int j=i+1; j<n; j++) if(s[j] == s[i]){
        id = j;
        break;
      }
      if(id != -1){
        //one swap
        swap(s[id], t[i]);
        swp.pb(ii(id, i));
        continue;
      }
      break;
    }

    if(s == t){
      cout << "Yes" << endl;
      cout << swp.size() << endl;
      for(ii p : swp) cout << p.ff + 1 << " " << p.ss+1 << endl;
    }
    else cout << "No" << endl;
  }
}

 
