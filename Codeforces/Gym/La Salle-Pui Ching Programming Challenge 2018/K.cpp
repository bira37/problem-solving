#include <bits/stdc++.h>
 
#define int long long
#define ff first
#define ss second
#define endl '\n'
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define EPS 1e-9
#define INF (int)1e18
#define ROOT 1
 
using namespace std;
 
inline int mod(int n){ return n%1000000007; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
int32_t main(){
  DESYNC;
  
  map<int,int> m;
  
  m[0] = 6;
    m[1] = 2;
      m[2] = 5;
        m[3] = 5;
          m[4] = 4;
            m[5] = 5;
              m[6] = 6;
                m[7] = 3;
                  m[8] = 7;
                    m[9] = 6;
                    
                    
  int e[20],d[20];
  
  memset(e,0,sizeof(e));
  memset(d,0,sizeof(d));
  
  e[0] =3;
    e[1] = 9;
      e[2] = 2;
        e[3] = 0;
          e[4] = 1;
            e[5] = 1;
              e[6] = 3;
                e[7] = 0;
                  e[8] = 3;
                    e[9] = 1;
                    
  d[0] = 3;
    d[1] = 8;
      d[2] = 1;
        d[3] = 3;
          d[4] = 3;
            d[5] = 2;
              d[6] = 2;
                d[7] = 3;
                  d[8] = 3;
                    d[9] = 3;      
      
   string x;
   
   int t;
   
   cin >> t;
   
   while(t--) {
   
     cin >> x;                  
     int n1, n2;
     
     n1 = x[0] - '0';
     n2 = x[1] - '0';
     
     int ans = m[n1] + m[n2]; 
     if(d[n1] == e[n2]) {
        if(d[n1] == 3) {
          ans -= 2;
        } else 
          ans--;
      }         
      
      cout << ans << endl; 
   
   }     
                                
                    
}
