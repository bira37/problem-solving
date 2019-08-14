#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int v[n];
	int sum = 0;
	for(int i=0; i<n; i++){
		cin >> v[i];
		sum+= v[i];
	}
	int i =0;
	int aux = 0;
	while(aux < sum/2) aux+=v[i++];
	cout << i << endl;
}

