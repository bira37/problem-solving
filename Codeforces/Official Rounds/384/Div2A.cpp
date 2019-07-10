#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,a,b;
	cin >> n >> a >> b;
	if(a > b) swap(a,b);
	string x;
	cin >> x;
	int ini = a-1;
	int fim = b-1;
	int cost = 0;
	//cout << ini << " " << fim << endl;
	while(ini < fim){
		int i;
		for(i = ini+1 ; i<=fim; i++){
			//cout << "entrou" << endl;
			//cout << x[ini] << " " << x[i] << endl;
			if(x[i] == x[ini]){
				ini = i;
			}
		}
		if(i == fim+1 && ini < fim){
			cost++;
			ini++;
		}
		//cout << ini << " " << cost << endl;
		//getchar();
	}
	cout << cost << endl;
}
