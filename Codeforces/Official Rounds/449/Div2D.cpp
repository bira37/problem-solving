#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define ii pair<int, int>
using namespace std;

int main(){
	int n,m,c;
	scanf("%d%d%d", &n, &m, &c);
	
	int sheet[n];
	for(int i=0; i<n; i++) sheet[i] = -1;
	for(int i=0; i<m; i++){
		int p;
		scanf("%d", &p);
		int ans;
		if(p <= c/2){
			for(int j=0; j<n; j++){
				if(sheet[j] == -1 || sheet[j] > p){
					sheet[j] = p;
					ans = j+1;
					break;
				}
			}
		}
		else {
			for(int j=n-1; j>=0; j--){
				if(sheet[j] < p){
					sheet[j] = p;
					ans = j+1;
					break;
				}
			}
		}
		printf("%d\n", ans);
		fflush(stdout);
		bool flag = true;
		for(int j=0; j<n; j++) if(sheet[j] == -1) flag = false;
		if(flag) break;
		
		
		
		
		
	}
}