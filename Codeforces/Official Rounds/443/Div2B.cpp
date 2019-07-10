#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	long long k;
	cin >> n >> k;
	int vic[n];
	int v[n];
	for(int i=0; i<n; i++){
		vic[i] = 0;
		cin >> v[i];
		v[i]--;
	}
	int aux[n];
	while(v[0] != n-1){
		if(v[0] > v[1]){
			vic[v[0]]++;
			if(vic[v[0]] == k){
				cout << v[0]+1 << endl;
				return 0;
			}
			aux[0] = v[0];
			for(int i=1; i<n; i++) aux[i] = v[i+1];
			aux[n-1] = v[1];
			for(int i=0; i<n; i++) v[i] = aux[i];
		}
		else {
			vic[v[1]]++;
			if(vic[v[1]] == k){
				cout << v[1]+1 << endl;
				return 0;
			}
			aux[0] = v[1];
			for(int i=1; i<n; i++) aux[i] = v[i+1];
			aux[n-1] = v[0];
			for(int i=0; i<n; i++) v[i] = aux[i];
		}
	}
	cout << n << endl;
}
