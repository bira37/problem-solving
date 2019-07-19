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
	string s;
	cin >> s;
	int n = s.size();
	for(int i=0; i<n; i++){
	  int num = (s[i] - '0');
	  if(num % 8 == 0){
      cout << "YES" << endl << num << endl;
      return 0;
    }
  }
	for(int i=0; i<n; i++){
	  for(int j=i+1; j<n; j++){
      int num = (s[i] - '0')*10 + (s[j] - '0');
      if(num % 8 == 0){
        cout << "YES" << endl << num << endl;
        return 0;
      }
	  }
	}
	for(int i=0; i<n; i++){
	  for(int j=i+1; j<n; j++){
	    for(int k = j+1; k < n; k++){
	      int num = (s[i] - '0')*100 + (s[j] - '0')*10 + (s[k] - '0');
	      if(num % 8 == 0){
	        cout << "YES" << endl << num << endl;
	        return 0;
	      }
	    }
	  }
	}
	cout << "NO" << endl; 
}
 
