#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int v[n];
		bool aux[n];
		for(int i=0; i<n; i++){
			scanf("%d", &v[i]);
			aux[i] = false;
		}
		int maior = 0;
		for(int i=0; i<n; i++){
			if(maior <= v[i]) aux[i] = true;
			maior = max(maior, v[i]);
		}
		int menor = 100000000;
		int ans = 0;
		for(int i=n-1; i>=0; i--){
			if(menor >= v[i] && aux[i] && i != n-1 && i != 0){
				ans++;
			}
			menor = min(menor, v[i]);
		}
		printf("%d\n", ans);
	}
}
