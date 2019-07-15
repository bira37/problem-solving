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
	int m;
	cin >> m;
	int h1,a1,x1,y1,h2,a2,x2,y2;
	cin >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
	int start = h2;
	int t1 = -1;
	int cur = h1;
	cur %= m;
	for(int i=1; i<=m; i++){
	  cur = cur*x1 + y1;
	  cur %= m;
	  if(cur == a1){
	    t1 = i;
	    break;
	  }
	}
	if(t1 == -1){
	  //cout << "t1" << endl;
	  cout << -1 << endl;
	  return 0;
	}
	h2 %= m;
	for(int i=1; i<=t1; i++){
	  h2 = h2*x2 + y2;
	  h2 %= m;
	}
	if(h2 == a2){
	  cout << t1 << endl;
	  return 0;
	}
	int t2 = -1;
	cur = a1*x1 + y1;
	cur %= m;
	if(cur == a1){
	  t2 = 1;
	}
	else {
	  for(int i = 2; i<=m; i++){
	    cur = cur*x1 + y1;
	    cur %= m;
	    if(cur == a1){
	      t2 = i;
	      break;
	    }
	  }
	}
	if(t2 == -1){
	  //cout << "t2" << endl;
	  cout << -1 << endl;
	  return 0;
	}
	int a = 1, b = 0;
	for(int i=0; i < t2; i++){
	  a = a*x2;
	  a %= m;
	  b = b*x2 + y2;
	  b %= m;
	}
	int steps = -1;
	for(int i=1; i<=m; i++){
	  h2 = h2*a + b;
	  h2 %= m;
	  if(h2 == a2){
	    steps = i;
	    break;
	  }
	}
	if(steps == -1){
	  //cout << "steps" << endl;
	  cout << -1 << endl;
	  return 0;
	}
	cout << steps*t2 + t1 << endl;
}