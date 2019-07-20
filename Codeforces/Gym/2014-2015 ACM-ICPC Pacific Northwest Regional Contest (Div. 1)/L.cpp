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
 
map<string, int> id;
double dist[100][100];
 
int32_t main(){
  //DESYNC;
  int t;
  cin >> t;
  for(int test = 1; test <= t; test++){
    cout << "Case " << test << ":" << endl;
    id.clear();
    int n;
    cin >> n;
    vector< tuple<int,int,int> > v(n+1);
    for(int i=1; i<=n; i++){
      string name;
      int x,y,z;
      cin >> name >> x >> y >> z;
      v[i] = make_tuple(x,y,z);
      id[name] = i;
    }
    
    for(int i=1; i<=n; i++){
      for(int j = 1; j<=n; j++){
        if(i == j) dist[i][j] = 0;
        else {
          int x1,y1,z1,x2,y2,z2;
          tie(x1,y1,z1) = v[i];
          tie(x2,y2,z2) = v[j];
          dist[i][j] = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
        }
      }
    }
    
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
      string a,b;
      cin >> a >> b;
      dist[id[a]][id[b]] = 0;
    }
    
    for(int k=1; k<=n; k++){
      for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    
    int q;
    cin >> q;
    while(q--){
      string a,b;
      cin >> a >> b;
      cout << "The distance from " << a << " to " << b << " is " << (int)round(dist[id[a]][id[b]]) << " parsecs." << endl;  
    }
  }
  
}
 
