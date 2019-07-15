#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,k;
	cin >> n >> k;
	int cnt[n][n];
	char mat[n][n];
	for(int i=0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> mat[i][j];
			cnt[i][j] = 0;
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			
			int ok = 0;
			for(int l = j; l < j + k && l < n; l++) ok += (mat[i][l] == '.');
			if(ok != k) continue;
			
			for(int l = j; l < j + k; l++) cnt[i][l]++;
		}
	}
	
	for(int j = 0; j<n; j++){
		for(int i=0; i<n; i++){
			int ok = 0;
			for(int l = i; l < i + k && l < n; l++) ok += (mat[l][j] == '.');
			if(ok != k) continue;
			for(int l = i; l < i+k; l++) cnt[l][j]++;
		}
	}
	pair<int,int> ans;
	int best = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			//cout << "cnt[" << i << "][" << j << "] = " << cnt[i][j] << endl;
			if(best < cnt[i][j]){
				best = cnt[i][j];
				ans = make_pair(i,j);
			}
		}
	}
	cout << ans.first+1 << " " << ans.second+1 << endl;
}