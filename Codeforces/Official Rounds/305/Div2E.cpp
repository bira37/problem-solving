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
#define INF (int)1e9
#define ROOT 1
#define N 512345
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
bitset<N> prime;
int lf[N];
int d[N] = {0};
int ans = 0;
bitset<N> in;
int cnt = 0;
int v[N];
int one = 0;
 
void run_sieve(int n){
	for(int i=0; i<=n; i++) lf[i] = i;
	prime.set();
	prime[0] = false;
	prime[1] = false;
	for(int p = 2; p*p <= n; p++){
		if(prime[p]){
			for(int i=p*p; i<=n; i+=p){
				prime[i] = false;
				lf[i] = min(lf[i], p);
			}
		}
	}
}
 
vector<int> factorize(int x){
  set<int> s;
  vector<int> fac;
  while(x > 1){
    s.insert(lf[x]);
    x /= lf[x];
  }
  for(int k : s) fac.pb(k);
  return fac;
}
 
void add(int x){
  //cout << "adding " << x << " with factors : ";
  vector<int> v = factorize(x);
  //for(int k : v) cout << k << " ";
  //cout << endl;
  int cur = 0;
  for(int msk = 1; msk < (1<<(int)v.size()); msk++){
    
    int num = 1;
    for(int i=0; i<v.size(); i++){
      if((1<<i) & msk) num *= v[i];
    }
    int mul = 1;
    if(__builtin_popcount(msk)%2 == 0) mul = -1;
    
    cur += mul*d[num];
  }
  
  for(int msk = 1; msk < (1<<(int)v.size()); msk++){
    
    int num = 1;
    for(int i=0; i<v.size(); i++){
      if((1<<i) & msk) num *= v[i];
    }
    
    d[num]++;
  }
  //cout << "cnt/cur " << cnt << " " << cur << endl;
  ans += ((cnt - cur));
}
 
void remove(int x){
  //cout << "removing " << x << " with factors : ";
  vector<int> v = factorize(x);
  int cur = 0;
  //for(int k : v) cout << k << " ";
  //cout << endl;
  for(int msk = 1; msk < (1<<(int)v.size()); msk++){
    
    int num = 1;
    for(int i=0; i<v.size(); i++){
      if((1<<i) & msk) num *= v[i];
    }
    
    d[num]--;
  }
  
  for(int msk = 1; msk < (1<<(int)v.size()); msk++){
    
    int num = 1;
    for(int i=0; i<v.size(); i++){
      if((1<<i) & msk) num *= v[i];
    }
    int mul = 1;
    if(__builtin_popcount(msk)%2 == 0) mul = -1;
    
    cur += mul*d[num];
  }
  //cout << "cnt/cur " << cnt << " " << cur << endl;
  ans -= ((cnt - cur));
}
 
void query(int x){  
  if(in[x]){
    in[x] = false;
    if(v[x] != 1){
      cnt--;
      remove(v[x]);
    }
    else one--;
  }
  else {
    in[x] = true;
    if(v[x] != 1){
      add(v[x]);
      cnt++;
    }
    else one++;
  }
}
 
int32_t main(){
	DESYNC;
	int n,q;
	cin >> n >> q;
	in.reset();
	run_sieve(500001);
	for(int i=0; i<n; i++){
	  cin >> v[i];
	}
	while(q--){
	  int x;
	  cin >> x;
	  x--;
	  query(x);
	  //cout << "cur ans " << ans << endl;
	  cout << ans + (one*(one-1))/2 + one*(cnt) << endl;
	}
}
