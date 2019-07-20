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
	int n;
	cin >> n;
	int v[n];
	for(int i=0; i<n; i++) cin >> v[i];
	int ans = 0;
	for(int i=0; i<n; i++){
	  int acc[n];
	  for(int j=0; j<n; j++) acc[j] = 0;
	  int first = -1, second = -1;
	  int idx_first = -1, idx_second = -1;
	  int bst = 0, cur = 0;
	  for(int j=i; j<n; j++){
	    if(first > v[j]){
	      cur--;
	    }
	    else {
	      acc[j] = -1;
	    }
	    if(v[j] > second){
	      if(v[j] < first){
          acc[idx_first]++;
          bst = max(acc[idx_first], bst);
        }
        second = v[j];
        idx_second = j;
      } 
      //sort maximums
      if(first < second){
        swap(first, second);
        swap(idx_first, idx_second);
      }
      cur++;
      ans += (bst+cur);
    }
  }
  cout << ans << endl;   
}
 
