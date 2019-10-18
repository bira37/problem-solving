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

struct pt{
  int x,y,z,id;
  pt(){}
  bool operator<(const pt & p) const{
    return tie(x,y,z,id) < tie(p.x, p.y, p.z, p.id);
  }
};

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  pt v[n];
  for(int i=0; i<n; i++){
    cin >> v[i].x >> v[i].y >> v[i].z;
    v[i].id = i;
  }
  sort(v, v+n);
  vector<bool> vis(n, false);
  for(int i=0; i<n; i++){
    if(vis[v[i].id]) continue;
    //cout << v[i].id << endl;
    //select min x
    int min_x = INF;
    for(int j=0; j<n; j++){
      if(i == j) continue;
      if(vis[v[j].id]) continue;
      min_x = min(min_x, v[j].x);
    }
    vector<pt> cands;
    for(int j=0; j<n; j++){
      if(i == j) continue;
      if(vis[v[j].id]) continue;
      if(v[j].x == min_x) cands.pb(v[j]);
    }
    //select min_y
    int min_y = INF;
    for(int j=0; j<cands.size(); j++){
      min_y = min(min_y, abs(v[i].y - cands[j].y));
    }
    vector<pt> cands2;
    for(int j=0; j<cands.size(); j++){
      if(abs(v[i].y - cands[j].y) == min_y) cands2.pb(cands[j]);
    }
    //select min_z
    int min_z = INF;
    int id = -1;
    for(int j=0; j<cands2.size(); j++){
      min_z = min(min_z, abs(v[i].z - cands2[j].z));
    }
    for(int j=0; j<cands2.size(); j++){
      if(abs(v[i].z - cands2[j].z) == min_z) id = cands2[j].id;
    }
    vis[v[i].id] = true;
    vis[id] = true;
    cout << v[i].id+1 << " " << id+1 << endl;
  }
}

 
