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
 
char mat[2123][2123];
int s[2123][2123];
int dx[] = {0, 1, 1, 2};
int dy[] = {1, 0, 2, 1};
int dx2[] = {-2, 0, 0, 2}; 
int dy2[] = {0, -2, 2, 0};
 
int32_t main(){
	DESYNC;
	int n,m;
	cin >> n >> m;
	for(int i=0; i<2*n-1; i++){
	  for(int j=0; j<2*m-1; j++){
	    cin >> mat[i][j];
	  }
	}
	queue< ii > q;
	for(int i=0; i<2*n-1-2; i+=2){
	  for(int j=0; j<2*m-1-2; j += 2){
	    s[i][j] = 4;
	    for(int k = 0; k<4; k++){
	      int px = i + dx[k];
	      int py = j + dy[k];
	      if(mat[px][py] == '.') s[i][j]--;
	    }
	    if(s[i][j] == 3) q.push(ii(i,j));
	  }
	}
	int ans = 0;
	while(!q.empty()){
	  int i = q.front().ff;
	  int j = q.front().ss;
	  //cout << i << " " << j << " " << mat[i][j] << endl;
	  q.pop();
	  if(s[i][j] == 4) continue;
	  s[i][j] = 4;
	  ans++;
	  
	  for(int k = 0; k<4; k++){
	    int px = i + dx[k];
	    int py = j + dy[k];
	    if(mat[px][py] == '-' || mat[px][py] == '|') continue;
	    mat[px][py] = '-';
	    if(i + dx2[k] >= 0 && j + dy2[k] >= 0 && i + dx2[k] < 2*n-1-2 && j + dy2[k] < 2*m-1-2){
	      s[i+dx2[k]][j+dy2[k]] = 4;
	      for(int k2 = 0; k2<4; k2++){
	        int px = i+dx2[k] + dx[k2];
	        int py = j+dy2[k] + dy[k2];
	        if(mat[px][py] == '.') s[i+dx2[k]][j+dy2[k]]--;
	      }
	      if(s[i+dx2[k]][j+dy2[k]] == 3) q.push(ii(i+dx2[k],j+dy2[k]));
	      else if(s[i+dx2[k]][j+dy2[k]] == 4) ans++;
	    }
	    break;
	  }
	}
	cout << ans << endl;
}
 
