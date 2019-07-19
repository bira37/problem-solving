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
 
int32_t main(){
	DESYNC;
	int k;
	cin >> k;
	int la = 1, ra = k;
	int lb = k+3, rb = k+2+k; 
	if(k%2 == 0){
	  cout << "NO" << endl;
	  return 0;
	}
	if(k == 1){
	  cout << "YES" << endl;
	  cout << "2 1" << endl << "1 2" << endl;
	  return 0;
	}
  vector< ii > e;
  e.pb(ii(la, lb));
  for(int i=la; i <= ra; i++){
    e.pb(ii(i, ra+1));
    e.pb(ii(i, ra+2));
  }
  for(int i=la+2; i<ra; i++){
    e.pb(ii(la, i));
  }
  for(int i=la+1; i<=ra; i++){
    for(int j=i+1; j<=ra; j++){
      e.pb(ii(i, j));
    }
  }
  for(int i=la+2; i<=ra-2; i+=2){
    if(find(e.begin(), e.end(), ii(i, i+1)) != e.end()) e.erase(find(e.begin(), e.end(), ii(i, i+1)));
  }
  la = lb;
  ra = rb;
  for(int i=la; i <= ra; i++){
    e.pb(ii(i, ra+1));
    e.pb(ii(i, ra+2));
  }
  for(int i=la+2; i<ra; i++){
    e.pb(ii(la, i));
  }
  for(int i=la+1; i<=ra; i++){
    for(int j=i+1; j<=ra; j++){
      e.pb(ii(i, j));
    }
  }
  for(int i=la+2; i<=ra-2; i+=2){
    if(find(e.begin(), e.end(), ii(i, i+1)) != e.end()) e.erase(find(e.begin(), e.end(), ii(i, i+1)));
  }
  cout << "YES" << endl;
  cout << 2*k+4 << " " << e.size() << endl;
  //int dg[2*k+4+1];
  //for(int i=0; i<=2*k+4; i++) dg[i] = 0;
  for(ii p : e){
    //dg[p.ff]++;
    //dg[p.ss]++;
    cout << p.ff << " " << p.ss << endl;
  }
  //for(int i=1; i<=2*k+4; i++) cout << "dg " << i << " = " << dg[i] << endl;
}
 
