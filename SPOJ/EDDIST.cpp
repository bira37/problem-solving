#include <bits/stdc++.h>

using namespace std;

int main(){
	int k;
	string x;
	while(cin >> k){
		if(k == -1){
			cin >> x;
			return 0;
		}
		cin >> x;
		int noA = 0;
		for(int i=0, len = x.size(); i<len; i++){
			if(x[i] != 'a') noA++;
		} 
		if(k >= x.size()) cout << endl;
		else if(noA <=k){
			for(int i=0; i<x.size() - noA - (k-noA); i++){
				cout << 'a';
			}
			cout << endl;
		}
		else {
			string ans = x;
			string aux;
			string minima;
			for(int insertion = 0; insertion <=k; insertion++){
				aux = x;
				for(int i=0, j=0, len = aux.size(); i<len && j < k-insertion; i++){
					if(aux[i] != 'a') {
						aux[i] = 'a';
						j++;
					}
				}
				aux = string(insertion, 'a') + aux;
				ans = min(ans, aux);
			}
			cout << ans << endl;
		}
	}
}

