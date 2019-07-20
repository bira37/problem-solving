#include <bits/stdc++.h>

#define int long long
#define ff first
#define ss second
#define endl '\n'
#define ii pair<string, string>
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

string red, blue;

map< ii, int> l, r;
string lleft, rright;

void generate_left(int i, int n){
  if(i == n){
    reverse(blue.begin(), blue.end());
    l[ii(red, blue)]++;
    reverse(blue.begin(), blue.end());
    return;
  }
  //paint red
  red += lleft[i];
  generate_left(i+1, n);
  red.pop_back();
  //paint blue
  blue += lleft[i];
  generate_left(i+1, n);
  blue.pop_back();
} 

void generate_right(int i, int n){
  if(i == n){
    reverse(blue.begin(), blue.end());
    r[ii(red, blue)]++;
    reverse(blue.begin(), blue.end());
    return;
  }
  //paint red
  red += rright[i];
  generate_right(i+1, n);
  red.pop_back();
  //paint blue
  blue += rright[i];
  generate_right(i+1, n);
  blue.pop_back();
}

int32_t main(){
	DESYNC;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
	  char c;
	  cin >> c;
	  lleft += c;
	}
	for(int i=0; i<n; i++){
	  char c;
	  cin >> c;
	  rright += c;
	}
	generate_left(0, n);
	generate_right(0,n);
	int ans = 0;
	for(auto p : l){
	  string pred = p.first.first;
	  string pblue = p.first.second;
	  int val = p.second;
	  //cout << "strings (" << pred << ", " << pblue << ") has clash with " << r[ii(pblue, pred)] << " strings " << endl;
	  ans += val*r[ii(pblue, pred)];
	}
	cout << ans << endl;
}


