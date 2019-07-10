#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,m;
	cin >> n >> m;
	int ans = n/m;
	int change = 0;
	int v[n];	
	int w[n];
	int hist[m+1];
	for(int i=0; i<=m; i++) hist[i] = 0;
 
	for(int i=0; i<n; i++){
		cin >> v[i];
		w[i] = v[i];
		if(v[i] <= m) hist[v[i]]++;
	}
 
	for(int i=0; i<n; i++){
		if(v[i] > m) v[i] = -1;
		else if(hist[v[i]] > ans){
			hist[v[i]]--;
			v[i] = -1;
		}
	}
 
	for(int i=1; i<=m; i++){
		for(int j=0; j<n && hist[i] < ans; j++){
			if(v[j] == -1){
				change++;
				v[j] = i;
				hist[i]++;
			}
		}
	}
 
	for(int i=0; i<n; i++) if(v[i] == -1) v[i] = w[i];
 
	cout << ans << " " << change << endl;
 
	for(int i=0; i<n; i++){
		if(!i) cout << v[i];
		else cout << " " << v[i];
	}
	cout << endl; 
		
	
	
}
