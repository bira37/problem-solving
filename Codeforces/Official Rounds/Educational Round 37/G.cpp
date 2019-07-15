#include <cstdio>
#include <vector>
#include <cmath>
#include <stdint.h>
#define int long long
#define endl '\n'
using namespace std;

bool prime[1123456] = {0};
int sp[1123456];
vector<int> otimizacaodeputa;

void sieve(){
  for(int i=0; i<1123456; i++) sp[i] = i;
  prime[1] = 1;
  sp[2] = 2;
  int sqr = sqrt(1123456);
  for(int i=2; i<=sqr; i++){
    if(prime[i]) continue;
    prime[i] = 1;
    sp[i] = i;
    for(int j=i+i; j<1123456; j+=i){
      prime[j] = 1;
      sp[j] = i;
    }
  }
}

void otimizaessecaralho(vector<int> & v){
  otimizacaodeputa.clear();
  int n = v.size();
  int ans = 0;
  for(int mask = 1; mask < (1LL<<n); mask++){
    int lcm = 1;
    for(int i=0; i<n; i++){
      if(mask & (1LL<<i)) lcm*=v[i]; 
    }
    if(__builtin_popcount(mask)%2 == 0) lcm = -1LL*lcm;
    otimizacaodeputa.push_back(lcm);
  }
}

int count(int m){
  int ans = 0;
  for(int x : otimizacaodeputa) ans += (m/x);
  return m - ans;
}

void solve(int & x,int & p, int & k){
  vector<int> v;
  int aux = p;
  while(aux > 1){
    v.push_back(sp[aux]);
    while(aux > 1 && sp[aux] == v.back()) aux /= sp[aux];
  }
  otimizaessecaralho(v);
  int tira = count(x);
  int l = 1, r = (int)1e11;
  int ans = -1;
  while(l <= r){
    int m = (l+r)>>1;
    if(count(m) - tira >= k){
      ans = m;
      r = m-1;
    }
    else l = m+1;
  }
  printf("%lld\n", ans);
}

int32_t main(){
  int t;
  sieve();
  scanf("%lld", &t);
  while(t--){
    int x,p,k;
    scanf("%lld%lld%lld", &x, &p, &k);
    if(p == 1) printf("%lld\n", x+k);
    else solve(x, p, k);
  }
}