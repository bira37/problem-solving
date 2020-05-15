#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	bool flag = false;
	while(cin >> n, n){
		if(flag) cout << endl;
		if(!flag) flag = true;
		vector<string> v(n);
		int maior = 0;
		for(int i =0; i<n; i++){
			cin >> v[i];
			int tam = v[i].size();
			maior = max(maior, tam);
		}

		for(int i=0; i<n; i++){
			cout << string(maior-v[i].size(), ' ') << v[i] << endl;
		}
	}
}
