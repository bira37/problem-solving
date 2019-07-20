#include <bits/stdc++.h>
 
//#define int long long
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
 
map< pair< vector<int>, int>, double> dp;
double DP(vector<int> v, int d) {
  //for(int i = 0; i <= 13; i++) {
  //  cout << i << " " << v[i] << endl; 
  //}
  
  pair< vector<int>, int> vd = make_pair(v,d);
  if(dp.count(vd)) return dp[vd];
  
  bool good = true;
  //int tene = 0;
  for(int i = 7; i <= 13; i++) {
    if(v[i]) {
      good = false;
      //tene += (i-7)*v[i];
    }
  }
  if(good) {
    //cout << "good" << endl;
    return 1.0; // Enemy team already died
  }
  if(d == 0) {
    //cout << "impossible" << endl;  
    return 0.0; // Enemy team cant die
  }
  //cout << "enemies total life " << tene << " " << d << endl;
  
  int numal = 0;
  for(int i = 1; i <= 13; i++) {
    if(v[i]) {
      numal += v[i];
    }
  }
  
  //cout << "alive " << numal << endl;
  
  //cout << endl << endl;
  
  dp[vd] = 0.0;
  for(int i = 1; i <= 6; i++) {
    if(v[i]) {
      v[i]--;
      if(i>1)
        v[i-1]++;
      dp[vd] += DP(v, d-1)*((double)(v[i]+1)/(double)numal);
      //cout <<"aqui " << dp[vd] << endl;
      if(i>1)
        v[i-1]--;
      v[i]++;
    }
  }
  
  for(int i = 8; i <= 13; i++) {
    if(v[i]) {
      v[i]--;
      if(i>8)
        v[i-1]++;
      dp[vd] += DP(v, d-1)*((double)(v[i]+1)/(double)numal);
      //cout <<"aqui " << dp[vd] << endl;      
      if(i>8)
        v[i-1]--;
      v[i]++;
    }
  }
  
  //for(int i = 0; i <= 13; i++) {
  //  cout << i << " " << v[i] << endl; 
  //}
  //cout << "D " << d << endl;
  //cout << dp[vd] << endl;
  
  return dp[vd];
}
 
 
int32_t main(){
  DESYNC;
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> v(14, 0);
  int h;
  for(int i = 0; i < n; i++) {
    cin >> h;
    v[h]++;
  }
  
  //vector<int> v2(7, 0);
  //int h;
  for(int i = 0; i < m; i++) {
    cin >> h;
    v[h+7]++;
  }
  
  cout << fixed << setprecision(10) << DP(v, min(d,61)) << endl;;
  
}
 
