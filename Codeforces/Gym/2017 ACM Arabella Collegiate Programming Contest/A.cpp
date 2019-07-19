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
	int t;
	cin >> t;
	while(t--){
	  int n;
	  cin >> n;
	  string ss;
	  cin >> ss;
	  string s = "0" + ss;
	  int acc = 0;
	  int f[2][n+1];
	  for(int i=0; i<=n; i++){
	    f[0][i] = f[1][i] = 0;
	  }
	  f[0][0] = 1;
	  int ans = 0;
	  int contador = 0;
	  bool achou = false;
	  for(int i=1; i<=n; i++){
	    acc += (s[i] == '1');
	    if(s[i] == '1'){
	      if(achou) ans -= max(0LL, (contador-1));
	      contador = 0;
	      achou = true;
	    }
	    else contador++;
	    if(i-3 >= 0) ans += f[!(acc%2)][i-3];
	    f[0][i] = f[0][i-1];
	    f[1][i] = f[1][i-1];
	    if(acc%2 == 1) f[1][i]++;
	    else f[0][i]++;
	    //cout << "it " << i << endl;
	    //cout << ans << " " << acc << endl;
	    //if(i-3 >= 0) cout << "f " << f[0][i-3] << " " << f[1][i-3] << endl;
	  }
	  if(achou) ans -= max(0LL, (contador-1));
	  contador = 0;
	  achou = false;
	  for(int i=n; i>=1; i--){
	    if(s[i] == '1'){
	      if(achou) ans -= max(0LL, (contador-1));
	      contador = 0;
	      achou = true;
	    }
	    else contador++;
	  }
	  if(achou) ans -= max(0LL, (contador-1));
	  cout << ans << endl;
	}
	    
}
 
