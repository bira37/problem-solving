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

bitset<10> has[201][201];
bool cycle[201][201];
bool discard[201][201];
int vis[201][201];
char mat[201][201];
int dx[10], dy[10];
int deg[201][201];
int n,m, q;

bool ciclando = false;
ii start(-1,-1);

bool valid(int i, int j){
  return i >= 0 && j >= 0 && i < n && j < m;
}

void go(int i, int j){
  vis[i][j] = 1;
  int num = mat[i][j] - '0';
  if(valid(i + dx[num], j + dy[num])){
    if(vis[i+dx[num]][j+dy[num]] == 1){
      ciclando = true;
      start = ii(i+dx[num], j + dy[num]);
      has[start.ff][start.ss][num] = true;
    }
    else if(vis[i+dx[num]][j+dy[num]] == 0){
      go(i+dx[num], j + dy[num]);
      if(ciclando) has[start.ff][start.ss][num] = true;
      if(i == start.ff && j == start.ss){
        cycle[i][j] = true;
        ciclando = false;
      }
    }
  }
  vis[i][j] = 2;
}

int32_t main(){
	DESYNC;
	cin >> n >> m >> q;
	for(int i=0; i<n; i++){
	  for(int j=0; j<m; j++){
	    cin >> mat[i][j];
	    vis[i][j] = 0;
	    cycle[i][j] = false;
	  }
	}
	
	for(int i=0; i<10; i++){
	  cin >> dx[i] >> dy[i];
	}
	
	for(int i=0; i<n; i++){
	  for(int j=0; j<m; j++){
	    if(vis[i][j] == 0) go(i,j);
	  }
	}
	
	for(int i=0; i<n; i++){
	  for(int j=0; j<m; j++){
	    int num = mat[i][j] - '0';
	    if(valid(i+dx[num], j + dy[num])) deg[i+dx[num]][j + dy[num]]++;
	  }
	}
	
	while(q--){
	  string s;
	  cin >> s;
	  bitset<10> suf[(int)s.size()];
	  suf[s.size()-1][s[(int)s.size()-1] - '0'] = true;
	  for(int i=(int)s.size()-2; i>=0; i--){
	    suf[i] |= suf[i+1];
	    suf[i][s[i]-'0'] = true;
	  }
	  
	  bool yes = false;
	  
	  for(int i=0; i<n && !yes; i++){
	    for(int j=0; j<m && !yes; j++){
	      if(deg[i][j] > 0 && !cycle[i][j]) continue;
	      //cout << "trying start on " << i << ", " << j << endl;
	      int x = i, y = j;
	      int p = 0;
	      int num = mat[x][y] - '0';
	      while(p < s.size() && !cycle[x][y]){
	        while(p < s.size() && mat[x][y] - '0' == s[p] - '0') p++;
	        if(!valid(x+dx[num], y+dy[num])) break;
	        x += dx[num], y += dy[num], num = mat[x][y] - '0';
	      }

	      if(p == s.size()){
	        yes = true;
	        break;
	      }
	      
	      if(cycle[x][y]){
	        if((has[x][y] & suf[p]) == suf[p]){
	          yes = true;
	          break;
	        }
	      }
	    }
	  }
	  
	  cout << (yes ? "YES" : "NO") << endl;
	}
	      
}