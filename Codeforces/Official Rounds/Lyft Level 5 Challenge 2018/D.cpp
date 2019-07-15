#include <bits/stdc++.h>

#define int unsigned long long
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
#define M 998244353
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

/* Erasthostenes Sieve Implementation + Euler's Totient */
/* Calculate primes from 2 to N */
/* lf[i] stores the lowest prime factor of i(logn factorization) */

namespace NT {

  const int MAX_N = 37608;
  
  bitset<MAX_N> prime;
  vector<int> primes;
  int lf[MAX_N];
  int totient[MAX_N];

  void Sieve(int n){
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
    for(int i=2; i<=n; i++) if(prime[i]) primes.pb(i);
  }

  void EulerTotient(int n){
    for(int i=0; i<=n; i++) totient[i] = i;
    for(int p = 2; p <= n; p++){
      if(totient[p] == p){
        totient[p] = p-1;
        for(int i=p+p; i<=n; i+=p){
          totient[i] = (totient[i]/p) * (p-1);
        }
      }
    }
  }
  
};

map<int,int> fac;

bool div5(int n){
  bool ok = false;
  for(int p : NT::primes){
    if(p*p*p*p == n){
      ok = true;
      fac[p] += 4;
      break;
    }
  }
  return ok;
}

bool div3(int n){
  int sqr = sqrt(n);
  for(int i=sqr-3; i<=sqr+3;  i++){
    if(i*i== n){
      fac[i]+=2;
      return true;
    }
  }
  return false;
}

bool div4p1(int n){
  int cbr = cbrt(n);
  if(cbr*cbr*cbr == n){
    fac[cbr]+=3;
    return true;
  }
  cbr++;
  if(cbr*cbr*cbr == n){
    fac[cbr]+=3;
    return true;
  }
  cbr++;
  if(cbr*cbr*cbr == n){
    fac[cbr]+=3;
    return true;
  }
  cbr-=3;
  if(cbr*cbr*cbr == n){
    fac[cbr]+=3;
    return true;
  }
  cbr--;
  if(cbr*cbr*cbr == n){
    fac[cbr]+=3;
    return true;
  }
  return false;
}  

int32_t main(){
  DESYNC;
  NT::Sieve(NT::MAX_N-1);
  int n;
  cin >> n;
  vector<int> check;
  vector<int> todo;
  int contador = 0;
  for(int i=0; i<n; i++){
    int x;
    cin >>x;
    if(div5(x)){
      continue;
    }
    else if(div3(x)){
      continue;
    }
    else if(div4p1(x)){
      continue;
    }
    else check.pb(x);
  }
 
  for(int x : check){
    bool ok = false;
    for(auto it : fac){
      if(x%it.ff == 0){
        fac[it.ff]++;
        fac[x/it.ff]++;
        ok = true;
        break;
      }
    }
    if(!ok) todo.pb(x);
  }    
  
  bool vis[todo.size()];
  for(int i=0; i<todo.size(); i++) vis[i] = false;
  
  for(int i=0; i<todo.size(); i++){
    for(int j=i+1; j<todo.size(); j++){
      if(todo[i] == todo[j]) continue;
      int g = gcd(todo[i], todo[j]);
      if(g != 1){
        if(!vis[i]){
          vis[i] = true;
          fac[g]++;
          fac[todo[i]/g]++;
        }
        if(!vis[j]){
          vis[j] = true;
          fac[g]++;
          fac[todo[j]/g]++;
        }
      }
    }
  }
  
  for(int i=0; i<todo.size(); i++){
    if(vis[i]) continue;
    bool ok = false;
    for(auto it : fac){
      if(todo[i]%it.ff == 0){
        fac[it.ff]++;
        fac[todo[i]/it.ff]++;
        ok = true;
        break;
      }
    }
    if(ok) vis[i] = true;
  }
  
  map<int, int> s;
  for(int i=0; i<todo.size(); i++){
     if(!vis[i]){
      s[todo[i]]++;
    }
  }
  
  
  int ans = 1;
  for(auto it : fac){
    ans *= (it.ss+1);
    ans = mod(ans, M);
  }
   for(auto it : s){
    ans *= (it.ss+1);
    ans = mod(ans, M);
    ans *= (it.ss+1);
    ans = mod(ans, M);
   }
  cout <<ans << endl;
}