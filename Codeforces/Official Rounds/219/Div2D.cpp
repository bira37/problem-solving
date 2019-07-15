#include <bits/stdc++.h>

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

bool mat[41][41];
int integral[41][41];
int cnt[41][41][41][41];
int p[41][41][41][41];
int n,m,q;

void calculate(){
  for(int i=0; i<=n; i++) integral[i][0] = 0;
  for(int j = 0; j<=m; j++) integral[0][j] = 0;
  for(int i=1; i<=n; i++){
    int acc = 0;
    for(int j=1; j<=m; j++){
      acc += mat[i][j];
      integral[i][j] = acc + integral[i-1][j];
    }
  }
}

int query(int a, int b, int c, int d){
  return integral[c][d] + integral[a-1][b-1] - integral[a-1][d] - integral[c][b-1];
}

void calculate2(){
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      for(int ofx = 0; ofx <= 40; ofx++){
        for(int ofy = 0; ofy <= 40; ofy++){
          if(i - ofx <= 0 || j - ofy <= 0) continue;
          cnt[i][j][ofx][ofy] = (query(i-ofx, j-ofy, i, j) == 0);
        }
      }
    }
  }
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      for(int ofx = 0; ofx <= 40; ofx++){
        int acc = 0;
        for(int ofy = 0; ofy <= 40; ofy++){
          acc += cnt[i][j][ofx][ofy];
          p[i][j][ofx][ofy] = acc + (ofx-1 >= 0 ? p[i][j][ofx-1][ofy] : 0);
        }
      }
    }
  }
}

int ans_query(int a, int b, int ofx, int ofy){
  //cout << a << " " << b << " " << c << " " << d << endl;
  //cout << c << " " << d << " -> " << p[c][d] << endl;
  //cout << a-1 << " " << b-1 << " -> " << p[a-1][b-1] << endl;
  //cout << a-1 << " " << d << " -> " << p[a-1][d] << endl;
  //cout << c << " " << b-1 <<  " -> " << p[c][b-1] << endl;
  return  p[a][b][ofx][ofy];
}

int32_t main(){
  scanf("%d%d%d", &n, &m, &q);
	for(int i=1; i<=n; i++){
	  for(int j=1; j<=m; j++){
	    char c;
	    cin >> c;
	    mat[i][j] = (c == '1');
	  }
	}
  calculate();
  calculate2();
  while(q--){
    int a,b,c,d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    long long ans = 0;
    for(int i=c; i>=a; i--){
      for(int j = d; j >=b; j--){
        int ofx = i-a;
        int ofy = j-b;
        ans += ans_query(i,j,ofx,ofy);
      }
    }
    cout << ans << endl;
  }
}