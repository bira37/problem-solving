#include <bits/stdc++.h>
 
using namespace std;
 
long long vet[100001];
 
int main(){
	long long n,k;
	for(int i=0; i<=100000; i++) vet[i] = 0;
	cin >> n >> k;
	long long res = 0;
	for(int a=0; a<n; a++){
		long long x;
		cin >> x;
		vet[x]++;
	}
	
	for(long long i=1; i<=100000; i++){
		long long j;
		j = i^k;
		if(j <= 100000 && i < j) res += vet[i]*vet[j]; 
		else if(i == j && vet[i]) {
			res += (vet[i]-1)*vet[i]/2;
		}
	}
	cout << res << endl;
}
