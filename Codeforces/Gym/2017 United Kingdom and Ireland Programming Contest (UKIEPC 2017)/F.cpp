#include <bits/stdc++.h>
using namespace std;
int n , k;
double dp[1005][1005];
bool vis[1005][1005];
 
double solve(int i ,int j){
	if(j == 0){
		return i;
	}
	if(vis[i][j]) return dp[i][j];
	vis[i][j] = 1;
	if(i == n){
		return dp[i][j] = 0.5000*solve(i-1 , j-1) + 0.50000*solve(i , j-1);
	}
	return dp[i][j] = 0.500*(solve(i + 1 , j - 1)  + solve(i , j - 1));
}
 
int main(){
	scanf("%d%d" , &n , &k);
	cout<<fixed<<setprecision(9)<<solve(0,k)<<endl;
}
