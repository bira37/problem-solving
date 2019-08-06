#include <bits/stdc++.h>

using namespace std;

int main(){
	int size,n;
	cin >> size >> n;
	int w[n];
	int v[n];
	
	for(int i=0; i<n; i++){
		cin >> w[i] >> v[i];
	}
	
	int dp[size+1];
//	for(int i=0; i<n; i++) dp[i][0] = 0;
	dp[0]=0;
	for(int i=1; i<=size; i++) dp[i] = -1;

	for(int i=0; i<n; i++){
		for(int j=size; j>=0; j--){
				if(j+w[i] <= size && dp[j] != -1)
					dp[j+w[i]] = max(dp[j+w[i]], dp[j]+v[i]);
		}
	}

	int maior = 0;
	for(int i=0; i<=size; i++) maior = max(maior, dp[i]);
	cout << maior << endl;
}

