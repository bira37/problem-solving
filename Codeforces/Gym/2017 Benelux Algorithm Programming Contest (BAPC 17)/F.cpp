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
	
	int num[n];
	for(int i  =0; i < n; i++) {
	  cin >> num[i];
	}
	sort(num, num+n);
	
	int a1 = 0, a2 = 0;
	
	for(int i = n-1; i >= 0; i-=2) {
	  a1 += num[i];
	}
	for(int i = n-2; i >= 0; i-=2) {
	  a2 += num[i];
	}
	cout << a1 << " " << a2 << endl;
}
 
