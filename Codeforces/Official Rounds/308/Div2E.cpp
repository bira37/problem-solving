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
string s;
 
int eval(int l, int r){
  int x = 0;
  int y = s[l] - '0';
  for(int i=l+1; i<r; i+=2){
    if(s[i] == '+'){
      x += y;
      y = s[i+1] - '0';
    }
    else {
      y *= s[i+1] - '0';
    }
  }
  return x + y;
}
 
int32_t main(){
	DESYNC;
	string ss;
	cin >> ss;
	s = "1*";
	s += ss;
	s += "*1";
	vector<int> pos;
	int ans = 0;
	for(int i = 0; i<s.size(); i++) if(s[i] == '*') pos.pb(i);
	for(int i=0; i<pos.size(); i++){
	  for(int j=i+1; j<pos.size(); j++){
	    int x = 0;
	    int y = s[0] - '0';
	    for(int k=1; k<s.size(); k+=2){
	      if(s[k] == '+'){
	        x += y;
	        y = s[k+1] - '0';
	      }
	      else {
	        if(k == pos[i]){
	          y*= eval(pos[i]+1, pos[j]-1);
	          k = pos[j]-2;
	        }
	        else y *= s[k+1] - '0';
	      }
	    }
	    ans = max(ans, x+y);
	  }
	}
	cout << ans << endl;
}
 
