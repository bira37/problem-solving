#include <bits/stdc++.h>

using namespace std;

int vet[1001];

int main(){
	int tamanho, n,teste=1;
	while( cin >> tamanho >> n, tamanho+n !=0){
		if(teste > 1) cout << endl;
		for(int i=0; i<=tamanho; i++){
			if(i==0) vet[i] = 0;
			else vet[i] = -1;
		}
		for(int j=0; j<n; j++){
			int size,num;
			cin >> size >> num;
			for(int i=tamanho-size; i>=0; i--){
				if(vet[i] != -1){
					vet[i+size] = max(vet[i]+num, vet[i+size]);
				}
			}
		}
		cout << "Teste " << teste++ << endl;
		int maior = 0;
		for(int i=0; i<=tamanho; i++){
			maior = max(maior,vet[i]);
		}
		cout << maior << endl;
	}
}

