#include <bits/stdc++.h>
#define ii pair<int, int>
#define mp make_pair
#define fr first
#define sc second
#define INF 0x3f3f3f3f
 
using namespace std;
 
int main(){
	int n,m,c;
	
	cin >> n >> m >> c;
	
	vector<ii> adj[n+1];
 
	for(int i=0; i<n; i++){
		adj[i].clear();
	}
 
	for(int i=0; i<m; i++){
		int x,y,t;
		cin >> x >> y >> t;
		adj[x].push_back(mp(y,t));
	}
 
	ii dp[n+1][n+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			dp[i][j].fr = INF;
			dp[i][j].sc = INF;
		}
	}
	dp[1][1].sc = 0;
	dp[1][1].fr = -1;
	//calculate from 1 to n
	
	for(int j=1; j<n; j++){
		for(int i=1; i<=n; i++){
			if(dp[i][j].sc != INF){
				for(int k=0; k<adj[i].size(); k++){
					if(dp[i][j].sc + adj[i][k].sc <= c){
						if(dp[adj[i][k].fr][j+1].sc > dp[i][j].sc + adj[i][k].sc){
							dp[adj[i][k].fr][j+1].sc = dp[i][j].sc + adj[i][k].sc;
							dp[adj[i][k].fr][j+1].fr = i;	
						}
					}
				}
			}
		}
	}
 
	int ans = 0;
	vector<int> res;
	int a,b;
	for(int i=n; i>=1; i--){
		if(dp[n][i].sc != INF){
			ans = i;
			a = n;
			b = i;
			break;
		}
	}
 
	while(dp[a][b].fr != -1){
		//cout << a << " " << b << " " << dp[a][b].fr << " " << dp[a][b].sc << endl;
		res.push_back(dp[a][b].fr);
		a = dp[a][b].fr;
		b--;
		//cout << a << " " << b << " " << dp[a][b].fr << " " << dp[a][b].sc << endl;
	}
 
	reverse(res.begin(), res.end());
		
	cout << ans << endl;
 
	for(int i=0; i<res.size(); i++){
		if(!i) cout << res[i];
		else cout << " " << res[i];
	}
	
	cout << " " << n << endl;
}
