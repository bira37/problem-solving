#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,nsub;
	cin >> n >> nsub;
	int mood[n];
	long long res = 0;
	for(int i=0; i<n; ++i){
		cin >> mood[i];
	}
	for(int i=0; i<nsub; ++i){
		int a,b;
		cin >> a >> b;
		a--; b--;
		int aux = 0;
		for(int j=a; j<=b; ++j){
			aux += mood[j];
		}
		if(aux > 0) res += aux;
	}	
	
	cout << res << endl;
}
