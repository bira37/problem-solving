#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,k;
	cin >> n >> k;
	int vet[n];
	int count = 0;
	for(int i=0; i<n;i++) cin >> vet[i];
	for(int i=1; i<n; i++){
		if(vet[i] + vet[i-1] <= k){
			int aux = k - vet[i-1] - vet[i];
			vet[i] += aux;
			count += aux;
		}
	}
	cout << count << endl;
	for(int i=0; i<n; i++){
		if(i==0) cout << vet[i];
		else cout << " " << vet[i];
	}
	cout << endl;
}
