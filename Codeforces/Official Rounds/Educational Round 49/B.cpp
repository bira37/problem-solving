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

int32_t main(){
  DESYNC;
  int n, q;
  cin >> n >>q;
  while(q--){
    int x,y;
    cin >> x >> y;
    if((x+y)%2 == 0){
      if(n%2 == 0){
        int cnt = (n/2)*(x-1);
        cnt += (y+1)/2;
        cout << cnt << endl;
      }
      else {
        int qtd1 = (x-1)/2;
        int qtd2 = (x-1) - qtd1;
        int cnt =  (n/2)*qtd1 + (n/2 + 1)*qtd2;
        cnt += (y+1)/2;
        cout << cnt << endl;
      }
    }
    else {
       if(n%2 == 0){
        int cnt = (n/2)*(x-1);
        cnt += (y+1)/2;
        cout << (n*n)/2 + (n%2) + cnt << endl;
      }
      else {
        int qtd2 = (x-1)/2;
        int qtd1 = (x-1) - qtd2;
        int cnt =  (n/2)*qtd1 + (n/2 + 1)*qtd2;
        cnt += (y+1)/2;
        cout << (n*n)/2 + (n%2) + cnt << endl;
      }
    }
  }
}

