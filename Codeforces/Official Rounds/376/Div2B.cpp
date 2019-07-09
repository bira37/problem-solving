#include <bits/stdc++.h>
 
using namespace std;
int vet[200000];
 
int main(){
	int k;
	cin >> k;
	for(int i=0; i<k; i++){
		cin >> vet[i];
	}
	int flag = 0;
	for(int i=0; i<k && !flag; i++){
		vet[i] = vet[i]%2;
		if(vet[i]==1){
			if(i < k-1 && vet[i+1]!=0){
				vet[i]--;
				vet[i+1]--;
			}
			else flag=1;
		}
	}
	if(!flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}
