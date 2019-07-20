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
 
bool cmp(const pair< vi, string >& a, const pair< vi, string >& b) {
  int i;
  for(i = 0; i < min(a.ff.size(), b.ff.size()); i++) {
    if(a.ff[i] > b.ff[i]) return true;
    else if(a.ff[i] < b.ff[i]) return false;
  }
  //for(; i < min(a.ff.size(), b.ff.size()); i++) {
  //  if((i >= a.ff.size() ? 1 : a.ff[i]) > (i >= b.ff.size() ? 1 : b.ff[i])) return true;
  //  if((i >= a.ff.size() ? 1 : a.ff[i]) < (i >= b.ff.size() ? 1 : b.ff[i])) return false;
  //}
  return a.ss < b.ss;
}
 
 
int32_t main(){
  //DESYNC;
 
  int n;
  cin >> n;
  
    pair< vi, string > pe[n];
  
  map<string, int> ma;
  ma["upper"] = 3;
  ma["middle"] = 2;
  ma["lower"] = 1;
  
  //cout << n << endl;
  
  for(int i = 0; i < n; i++) {
    int l = 0;
    cin >> pe[i].ss;  
    pe[i].ss.pop_back();
    //cout << pe[i].ss << endl;
    string cla;
    while(cin >> cla, cla != "class") {
      //cout << cla << " ";
      pe[i].ff.push_back(ma[cla]);
    }
    
    reverse(pe[i].ff.begin(), pe[i].ff.end());
    //cout << endl;
  }
  
  int maxi = 0;
   for(int i = 0; i < n; i++) maxi = max(maxi, (long long)pe[i].ff.size());
   //cout << maxi << endl;
   for(int i = 0; i < n; i++) {
    while(pe[i].ff.size() < maxi) pe[i].ff.push_back(2);
   }
  
  //cout << endl;
  
  sort(pe, pe+n, cmp);
  
  for(int i = 0; i < n; i++) {
    cout << pe[i].ss << endl;
  }
  
}
 
