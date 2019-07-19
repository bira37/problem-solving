#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	char mat[n][m];
	vector< tuple<int,int,int> > star;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> mat[i][j];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mat[i][j] != '*') continue;
			int sz = INF;
			int k = j;
			int cur = -1;
			while(mat[i][k] == '*' && k < m){
				cur++;
				k++;
			}
			sz = min(sz, cur);
			k = j;
			cur = -1;
			while(mat[i][k] == '*' && k >=0 ){
				cur++;
				k--;
			}
			sz = min(sz, cur);
			
			k = i;
			cur = -1;
			while(mat[k][j] == '*' && k >=0 ){
				cur++;
				k--;
			}
			
			sz = min(sz, cur);
			
			k = i;
			cur = -1;
			while(mat[k][j] == '*' && k < n ){
				cur++;
				k++;
			}
			
			sz = min(sz, cur);
			
			if(sz > 0) star.pb(mt(i,j,sz));
		}
	}
	char ue[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) ue[i][j] = '.';
	}
	for(auto tp : star){
		int i,j,k;
		tie(i,j,k) = tp;
		
		for(int x = i; x <= i+k; x++){
			ue[x][j] = '*';
		}
		for(int x = i; x >= i-k; x--){
			ue[x][j] = '*';
		}
		
		for(int x = j; x <= j+k; x++){
			ue[i][x] = '*';
		}
		
		for(int x = j; x >= j-k; x--){
			ue[i][x] = '*';
		}
	}
	
	bool ok = true;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) if(mat[i][j] != ue[i][j]) ok = false;
	}
	if(!ok){
		cout << "-1" << endl;
		return 0;
	}
	cout << star.size() << endl;
	for(auto tp : star){
		int i,j,k;
		tie(i,j,k) = tp;
		cout << i+1 << " " << j+1 << " " << k << endl;
	}
		
}
