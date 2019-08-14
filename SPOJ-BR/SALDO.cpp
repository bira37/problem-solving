#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,teste=1;
	while(cin >> n, n!=0){
		int ini=1,s,e,sum=0,saldoanterior=0;
		for(int i=1; i<=n; i++){
			int x,y;
			cin >> x >> y;
			if((x-y)+sum >=0){
				sum += (x-y);
			}
			else {
				sum = 0;
				ini = i+1;
			}
			if(sum > saldoanterior || (sum == saldoanterior && i-ini > e-s)){
				saldoanterior = sum;
				s = ini;
				e = i;
			}
		}
		cout << "Teste " << teste++ << endl;
		if(saldoanterior > 0) {
			cout << s << " " << e << endl;
		}
		else cout << "nenhum" << endl;
		cout << endl;
	}
}

