#include <bits/stdc++.h>

#define int long long
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

int exp(int a, int k){
  if(a == 1) return 1LL;
  if(k == 1) return a;
  int aux = exp(a, k/2);
  aux = mod(aux*aux, M);
  if(k%2) aux = mod(aux*a, M);
  return aux;
}

bool prime(int x){
  if(x == 1) return false;
  if(x == 2) return true;
  if(x%2 == 0) return false;
  for(int i=3; i<=sqrt(x); i+=2){
    if(x%i == 0) return false;
  }
  return true;
}

void solve(){
  int first = 31623;
  cout << 1 << " " << first << endl;
  fflush(stdout);
  int ans;
  cin >> ans;
  int x = first*first - ans;
  int can = -1;
  map<int,int> occ;
  for(int i=1, len = sqrt(x); i <= len; i++){
    if(x%i != 0) continue;
    if(i > ans and prime(i)){
      can = max(can, i);
      occ[i]++;
    }
    if(i != x/i and x/i > ans and prime(x/i)){
      can = max(can, x/i);
      occ[x/i]++;
    }
  }
  
  if(occ.size() == 1){
    cout << 2 << " " << occ.begin()->first << endl;
    fflush(stdout);
    string ans;
    cin >> ans;
    if(ans == "Yes") return;
    else exit(0);
  }
  
  if(occ.size() == 0){
    exit(0);
  }
  
  for(int k =1;; k++){
    first = k;
    if(k*k > can) break;
  }
  
  cout << 1 << " " << first << endl;
  fflush(stdout);
  cin >> ans;
  
  x = first*first - ans;
  
  for(int i=1, len = sqrt(x); i<= len; i++){
    if(x%i != 0) continue;
    if(i > ans and prime(i)){
      occ[i]++;
    }
    if(i != x/i and x/i > ans and prime(x/i)){
      occ[x/i]++;
    }
  }
  
  for(ii p : occ){
    if(p.ss == 2){
      cout << 2 << " " << p.ff << endl;
      fflush(stdout);
      string ans;
      cin >> ans;
      if(ans == "Yes") return;
      else exit(0);
    }
  }
  
  exit(0);
  
}

int32_t main(){
  int t;
  cin >> t;
  while(t--) solve();

}


