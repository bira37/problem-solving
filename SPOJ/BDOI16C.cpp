#include <cstdio>
#define M 10007
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int w=1; w<=t; w++){
		int n, k;
		scanf("%d%d", &n, &k);
	
		int dp[n+1][k+1];
		int sum[k+1];
		for(int i=0; i<=k; i++) dp[1][i] = 0;
		dp[1][0] = 1;
		sum[0] = 1;
		for(int i=1; i<=k; i++){
			sum[i] = sum[i-1] + dp[1][i];
			sum[i] %= M;
		}
	
		for(int i=2; i<=n; i++){
			dp[i][0] = 1;
			for(int j = 1; j<=k; j++){
				int tira = 0;
				if(j - (i-1) -1 >= 0) tira = sum[j-(i-1)-1];
				dp[i][j] = sum[j] - tira;
				dp[i][j] = (dp[i][j]%M + M)%M;
			}
		
			sum[0] = 1;
			for(int j=1; j<=k; j++){
				sum[j] = sum[j-1] + dp[i][j];
				sum[j] %= M;
			}
		}
	
		int fat = 1;
		for(int i=1; i<=n; i++){
			fat*=i;
			fat%=M;
		}
		/*for(int i=1; i<=n; i++){
			for(int j=0; j<=k; j++){
				cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
			}
		}*/
		if(k > 0) printf("Case %d: %d\n", w, ((fat - sum[k-1])%M + M)%M);
		else printf("Case %d: %d\n", w, fat%M);
	}
}
	 
	
