#include <bits/stdc++.h>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define ff first
#define ss second
#define MAX int32_t(1e6)+1
#define INF int32_t(2e9)+1
#define m(x, v) memset(x, v, sizeof(x))
#define endl "\n"
#define DEBUG(x) cout << #x << " = " << x << endl
using namespace std;
 
int32_t main(){
    DESYNC;
    int t;
    cin >> t;
    while(t--){
      int n, m;
      cin >> n >> m;
      map<string, pair<int, ii> > catalog;
      for(int i=0; i<n; ++i){
        string s;
        int p, q, c;
        cin >> s >> p >> q >> c;
        catalog[s] = {p, {q, c}};
      }
      
      vii spys;
      vector<string> cars;
      map<string, int> spytoidx;
      int idx=1;
      for(int i=0; i<m; ++i){
        int tim;
        cin >> tim;
        string s;
        cin >> s;
        if(!spytoidx[s]){
          spytoidx[s] = idx++;
          spys.pb({0, 0});
          cars.pb("\0");
        }
        char c;
        cin >> c;
        if(c=='a'||c=='r'){
          int value;
          cin >> value;
          if(spys[spytoidx[s]-1].ss != 1){
            spys[spytoidx[s]-1].ss = -1;
          }
          else{
            if(c=='a')
              spys[spytoidx[s]-1].ff += (value*catalog[cars[spytoidx[s]-1]].ff+100-1)/100;
            else{
              spys[spytoidx[s]-1].ff += value*catalog[cars[spytoidx[s]-1]].ss.ss;
              spys[spytoidx[s]-1].ss = 0;
              cars[spytoidx[s]-1] = "\0";
            }
          }
 
        }
        else{
          string car;
          cin >> car;
          if(spys[spytoidx[s]-1].ss != 0){
            spys[spytoidx[s]-1].ss = -1;
          }
          else{
            spys[spytoidx[s]-1].ss = 1;
            spys[spytoidx[s]-1].ff += catalog[car].ss.ff;
            cars[spytoidx[s]-1] = car;
          }
        }
      }
      for(auto p : spytoidx){
        string name = p.ff;
        cout << name << ' ';
        idx = p.ss-1;
        if(spys[idx].ss == 0){
          cout << spys[idx].ff << endl;
        }
        else{
          cout << "INCONSISTENT" << endl;
        }
      }
    }
    return 0;
}
