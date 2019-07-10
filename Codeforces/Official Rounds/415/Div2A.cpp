#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,k;
	cin >> n >> k;
	int ans = 0;
	int sum = 0, qtd = n;
	for(int i = 0; i<n; i++){
		int x;
		cin >> x;
		sum+=x;
	}
	cout << fixed << setprecision(5);
	while(true){
		int aux = sum/qtd;
		double aux2 = (double)aux;
		//cout << sum/(qtd*1.0) << endl;
		if(sum/(qtd*1.0) - aux*1.0 > 0.4999999999999999){
			aux++;
		}
		if(aux == k) break;
		sum+=k;
		qtd++;
		ans++;
	}
	cout << ans << endl;
}
