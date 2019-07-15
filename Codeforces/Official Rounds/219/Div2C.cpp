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
	int n;
	cin >> n;
	multiset<int> low, high;
	int v[n];
	for(int i=0; i<n; i++){
	  int x;
	  cin >> x;
	  v[i] = x;
	}
	sort(v, v+n);
	for(int i=0; i<n; i++){
	  if(i < n/2) low.insert(v[i]);
	  else high.insert(v[i]);
	}
	int ans = 0;
	//for(int x : low) cout << x << " ";
	//cout << endl;
	//for(int x : high) cout << x << " ";
	//cout << endl;
  for(int x : low){
    auto it = high.lower_bound(2*x);
    if(it != high.end()){
      high.erase(it);
      ans++;
    }
  }
  cout << n - ans << endl;
}