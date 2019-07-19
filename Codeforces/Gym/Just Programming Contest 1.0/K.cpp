#include <bits/stdc++.h>
 
#define int long long
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
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
struct submission{
  int team, prob, judge;
  string tempo;
  bool operator<(const submission & b) const{
    return tempo < b.tempo;
  }
};
 
int32_t main(){
  DESYNC;
	int t;
  cin >> t;
  while(t--){
    int n,m,k;
    cin >> m >> n >> k;
    int problem[m+1];
    int fail_team[n+1][m+1];
    int max_fail[n+1];
    int max_ac[n+1];
    int first_ac = -1;
    int last_ac = -1;
    for(int i=0; i<m+1; i++) problem[i] = -1;
    for(int i=0; i<n+1; i++){
      max_fail[i] = -1;
      max_ac[i] = 0;
      for(int j=0; j<m+1; j++) fail_team[i][j] = 0;
    }
    submission v[k];
    for(int i=0; i<k; i++){
      cin >> v[i].prob >> v[i].team >> v[i].judge >> v[i].tempo;
    }
    sort(v, v+k);
    for(int i=0; i<k; i++){
      int team = v[i].team, prob = v[i].prob, judge = v[i].judge;
      if(judge == 1 && problem[prob] == -1){
        problem[prob] = team;
      }
      if(judge == 1 && first_ac == -1) first_ac = team; 
      if(judge == 1) last_ac = team;
      if(judge == 1){
        if(fail_team[team][prob] == 0) max_ac[team]++;
      }
      if(judge == 1){
        if(fail_team[team][prob] > 0){
          max_fail[team] = max(max_fail[team], fail_team[team][prob]);
        }
      }
      if(judge == 0){
        fail_team[team][prob]++;
      }  
    }
    int solid = 1;
    for(int i=2; i<=n; i++){
      if(max_ac[i] > max_ac[solid]) solid = i;
    }
    int relentless = 1;
    for(int i=2; i<=n; i++){
      if(max_fail[i] > max_fail[relentless]) relentless = i;
    }
    for(int i=1; i<=m; i++){
      cout << problem[i] << " ";
    }
    cout << endl;
    cout << first_ac << " " << last_ac << " " << solid << " " << relentless << endl;
  }
}
