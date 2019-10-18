#include <bits/stdc++.h>

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
#define INF 2e9
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

  //fucking compress
  set<int> comp;
  for(int i=0; i<n; i++){
    comp.insert(v[i].x);
  }
  vector<int> aux;
  for(int x : comp) aux.pb(x);
  set< tuple<int,int> > bucket[comp.size()];
  map<int, set< tuple<int,int> > > bz[comp.size()];
  for(int i=0; i<n; i++){
    v[i].x = lower_bound(aux.begin(), aux.end(), v[i].x) - aux.begin();
    bucket[v[i].x].insert(mt(v[i].y, v[i].id));
    bz[v[i].x][v[i].y].insert(mt(v[i].z, v[i].id));
  }

  int pt = 0;
  while(pt < comp.size()){

    if(bucket[pt].size() == 0){
      pt++;
      continue;
    }

    int ans1 = get<1>(*bucket[pt].begin());
    bucket[pt].erase(bucket[pt].begin());
    bz[pt][v[ans1].y].erase(mt(v[ans1].z, ans1));
    //choices
    int ans2;
    if(bucket[pt].size() > 0){
      int y = get<0>(*bucket[pt].begin());
      int min_z = INF;
      auto it = bz[pt][y].lower_bound(mt(v[ans1].z, -1));
      vector<int> zs;
      if(it != bz[pt][y].end()){
        if(min_z > abs(get<0>(*it) - v[ans1].z)){
          zs.pb(get<0>(*it));
          min_z = abs(get<0>(*it) - v[ans1].z);
          ans2 = get<1>(*it);
        }
      }
      if(it != bz[pt][y].begin()){
        it--;
        if(zs.size() == 0 or abs(zs.front() - v[ans1].z) == abs(get<0>(*it) - v[ans1].z)){
          if(min_z > abs(get<0>(*it) - v[ans1].z)){
            min_z = abs(get<0>(*it) - v[ans1].z);
            ans2 = get<1>(*it);
          }
        }
      }
      bucket[pt].erase(mt(v[ans2].y, ans2));
      bz[pt][v[ans2].y].erase(mt(v[ans2].z, ans2));
      cout << ans1+1 << " " << ans2+1 << endl;
      //cout << "same bucket match" << endl;

    }
    else {
      vector<int> ys;
      auto it = bucket[pt+1].lower_bound(mt(v[ans1].y, -1));
      if(it != bucket[pt+1].end()) ys.pb(get<0>(*it));
      if(it != bucket[pt+1].begin()){
        it--;
        if(ys.size() == 0 or abs(ys.front() - v[ans1].y) == abs(get<0>(*it) - v[ans1].y)) ys.pb(get<0>(*it));
      }
      int min_z = INF;
      for(auto y : ys){
        auto it = bz[pt+1][y].lower_bound(mt(v[ans1].z, -1));
        vector<int> zs;
        if(it != bz[pt+1][y].end()){
          if(min_z > abs(get<0>(*it) - v[ans1].z)){
            zs.pb(get<0>(*it));
            min_z = abs(get<0>(*it) - v[ans1].z);
            ans2 = get<1>(*it);
          }
        }
        if(it != bz[pt+1][y].begin()){
          it--;
          if(zs.size() == 0 or abs(zs.front() - v[ans1].z) == abs(get<0>(*it) - v[ans1].z)){
            if(min_z > abs(get<0>(*it) - v[ans1].z)){
              min_z = abs(get<0>(*it) - v[ans1].z);
              ans2 = get<1>(*it);
            }
          }
        }
      }
      bucket[pt+1].erase(mt(v[ans2].y, ans2));
      bz[pt+1][v[ans2].y].erase(mt(v[ans2].z, ans2));
      cout << ans1+1 << " " << ans2+1 << endl;
    }

  }
}

 
