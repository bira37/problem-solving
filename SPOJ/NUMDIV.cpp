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

namespace NT{
  
  int mulmod(int a, int b, int c){
    int x = 0,y=a%c;
    
    while(b > 0){
    
      if(b%2 == 1){
        x = (x+y)%c;
      }
      
      y = (y*2)%c;
      b /= 2;
    }
    
    return x%c;
  }
  
  int expmod(int a, int k, int p){
    if(k == 0) return 1;
    if(k == 1) return a;
    
    int aux = expmod(a, k/2, p);
    aux = mulmod(aux, aux, p);
    
    if(k%2) aux = mulmod(aux, a, p);
    return aux;
  } 
  
  bool PrimalityTest(int p, int iterations){
    //Miller Rabin Primality Test
    mt19937 mt_rand(time(0));
    
    if(p < 2) return false;
    if(p == 2) return true;
    if(p%2 == 0) return false;
    
    int fixed_s = p-1;
    while(fixed_s%2 == 0) fixed_s /= 2;
    
    for(int iter = 0; iter < iterations; iter++){

      int s = fixed_s;
      
      int a = mt_rand()%(p-1) + 1;
      int b = expmod(a, s, p);
      
      while(s != p-1 && b != 1 && b != p-1){
        b = mulmod(b,b,p);
        s *= 2;
      }
      
      if(b != p-1 && s%2 == 0) return false;
      
    }
    
    return true;
    
  }
  
}

namespace NT{

  int CountDivisors(int x){
    
    int ans = 1;
    for(int i=2; i*i*i <= x; i++){
      int cnt = 1;
      while(x%i == 0){
        cnt++;
        x/=i;
      }
      ans*=cnt;
    }
    
    if(PrimalityTest(x,10)) ans*=2;
    else if((int)sqrt(x)*(int)sqrt(x) == x && PrimalityTest((int)sqrt(x), 10)) ans*=3;
    else if(x != 1) ans*=4;
    
    return ans;
  }
  
}

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << NT::CountDivisors(n) << endl;
  }  
}


