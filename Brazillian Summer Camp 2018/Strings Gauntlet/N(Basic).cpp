#include <bits/stdc++.h>

using namespace std;

int sz[27];

int solve(int n, int k){
	if(k == (sz[n]/2)+1) return 0;
	else if(k > (sz[n]/2)+1) return (k - ((sz[n]/2)+1));
	else return solve(n-1, k);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	sz[1] = 1;
	for(int i=2; i<=26; i++){
		sz[i] =2*sz[i-1]+1;
	}
	while(cin >> n >> k){
		k++;
		if(k == 1) cout << 0 << endl;
		else cout << solve(n, k) << endl;
	}	
}	
