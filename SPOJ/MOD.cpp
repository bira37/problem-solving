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
const double PI = acos(-1);

using namespace std;

inline int mod(int n){ return (n%1000000007); }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

int discrete_log(int a, int b, int p){
  a %= p, b %= p;
	
  if(b == 1) return 0;
	
  int cnt = 0, t = 1;
  for(int g = gcd(a, p); g != 1; g = gcd(a, p)){
    if(b % g) return -1;
		
    p /= g, b /= g, t = t * a / g % p;
    cnt++;
		
    if(b == t) return cnt;
  }

  map<int, int> hash;
  int m = (sqrt(p) + 1);
  int base = b;
	
  for(int i = 0; i != m; ++i){
    hash[base] = i;
    base = base * a % p;
  }
	
  base = 1;
  for(int i=0; i<m; i++){
    base = (base*a)%p;
  }

  int cur = t;
  for(int i = 1; i <= m + 1; ++i){
    cur = cur * base % p;
    if(hash.count(cur)) return i * m - hash[cur] + cnt;
  }
  return -1;
}

int32_t main(){
  DESYNC;
  int a,b,m;
  while(cin >> a >> m >> b, a+m+b != 0){
    int ans = discrete_log(a,b,m);
    cout << (ans != -1 ? to_string(ans) : "No Solution") << endl;
  }
}


