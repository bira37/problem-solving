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
loop:  while(q--){
    int n;
    cin >> n;
    n *= 4;
    int v[n];
    vector<int> a;
    for(int i=0; i<n; i++){
      cin >> v[i];
    }
    sort(v, v+n);
    for(int i=0; i<n; i+=2){  
      if(v[i] != v[i+1]){
        cout << "NO" << endl;
        goto loop;
      }
      a.pb(v[i]);
    }
    
    //check all
    int ar = a.front()*a.back(); 
    for(int i = 0, j = (int)(a.size()-1); i<a.size()/2; i++, j--){
      if(ar != a[i]*a[j]){
        cout << "NO" << endl;
        goto loop;
      }
    }
    
    cout << "YES" << endl;
  }
      
}
