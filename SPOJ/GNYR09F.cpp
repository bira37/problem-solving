#include <bits/stdc++.h>
#define LL_MAX LLONG_MAX
#define ll long long
using namespace std;

ll memo[101][2][101];
int caso,n,s;

ll dp(int i, int j, int s){
	if(i < 0 || s < 0) return 0; //elemento "neutro"
	else if(memo[i][j][s] != -1) return memo[i][j][s];
	else if(i==0 && s == 0) memo[i][j][s] =  1;
	else if(i == 0) memo[i][j][s] =  0;
	else if(j == 1) memo[i][j][s] = dp(i-1, j, s-1) + dp(i-1, !j, s);
	else memo[i][j][s] = dp(i-1,j,s) + dp(i-1,!j, s);
	//cout << "memo[" << i << "][" << j << "][" << s << "] = " << memo[i][j][s] << endl;
	return memo[i][j][s]; 
} 

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> caso >> n >> s;
		for(int i=0; i<=n; i++){
			for(int j=0; j<2; j++){
				for(int k=0; k<=s; k++){
					memo[i][j][k] = -1;
				}
			}
		}
		cout << caso << " " << dp(n-1,0,s) + dp(n-1,1,s) << endl;
	}
}
	
