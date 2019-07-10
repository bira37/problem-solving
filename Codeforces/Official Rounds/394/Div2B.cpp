#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int barrier[n], barrier2[n];
	int posb[n];
	int dist[n];
	for(int i=0; i<n; i++){
		cin >> barrier[i];
		barrier2[i] = barrier[i];
	}
	for(int i=0; i<n; i++){
		cin >> dist[i];
	}
	bool flag;
	bool ans = false;
	for(int ini=0; ini<m && ans == false; ini++){
		int start;
		int j;
		for(j=0; j<n; j++){
			start = ini + dist[j];
			start = start%m;
			flag = false;
			for(int k=0; k<n; k++){
				if(barrier[k] == start){
					flag = true;
					barrier[k] = m+5;
				}
			}
			if(flag == false) break; 
		}
		if(j == n) ans = true;
		for(int i=0; i<n; i++){
			barrier[i] = barrier2[i];
		}
	}
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;	  
}
