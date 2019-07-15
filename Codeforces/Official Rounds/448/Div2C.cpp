#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
#define int long long
void process(vector<int> & primes){
	for(int i=2; i<=70; i++){
		bool flag = true;
		for(int j=2; j<=sqrt(i); j++){
			 if(i%j == 0) flag = false;
		}
		if(flag) primes.push_back(i);
	}
}

int dp[2][(1<<19)] = {0};
int ways[71][2];
int mask[71];	

int32_t main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=0; i<=70; i++){
		ways[i][0] = 1;
		ways[i][1] = 0;
	}
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		ways[x][0] = ways[x][1] = ways[x][0] + ways[x][1];
		ways[x][0] %= M;
		ways[x][1] %= M;
	}
	
	vector<int> primes;
	process(primes);
	
	for(int i=1; i<=70; i++){
		mask[i] = 0;
		int num = i;
		for(int j=0; j<primes.size(); j++){
			while(num%primes[j] == 0){
				mask[i] ^= (1<<j);
				num/=primes[j];
			}
		}
	}
	

	dp[0][0] = 1;
	for(int i=0; i<70; i++){
		for(int j=0; j<(1<<19); j++){
			dp[(i+1)%2][(mask[i+1]^j)] += (dp[i%2][j]*ways[i+1][1])%M;
			dp[(i+1)%2][j] += (dp[i%2][j]*ways[i+1][0])%M;
			dp[(i+1)%2][(mask[i+1]^j)] %= M;
			dp[(i+1)%2][j] %= M;
		}
		for(int j=0; j<(1<<(int)primes.size()); j++){
			dp[(i%2)][j] = 0;
			
		}
	}
	cout << ((dp[0][0]-1)%M + M)%M << endl;
}