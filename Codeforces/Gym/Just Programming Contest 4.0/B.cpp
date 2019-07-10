#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m, cont = 0;
		scanf("%d%d", &n, &m);
		int vet[n];
		for (int i=0; i<n; i++){
			scanf("%d", &vet[i]);
			if (vet[i] == -1 && i>0 && vet[i-1]!=-1){
				vet[i] = (vet[i-1]+1) % m;
			}
			else if (vet[i] == -1) cont++;
		}
		while(cont){
			for (int i = n-2; i >= 0; i--){
				if (vet[i] == -1 && vet[i+1] != -1){
					cont--;
					vet[i] = (vet[i+1] - 1) % m;
					if (vet[i] < 0) vet[i]+=m;
				}
			}
			for (int i=1; i<n; i++){
				if (vet[i] == -1 && vet[i-1] != -1){
					cont--;
					vet[i] = (vet[i-1] + 1) % m;
				}
			}
		}
		printf("%d", vet[0]);
		for (int i=1; i<n; i++){
			printf(" %d", vet[i]);
		}
		printf("\n");
	}
}
