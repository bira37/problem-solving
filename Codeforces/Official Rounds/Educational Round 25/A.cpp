#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	int ans = 0;
	cin >> n;
	string s;
	cin >> s;
	int cont = 0;
	for(int i=0; i<n; i++){
		if(cont == 0 && s[i] == '0') {
			ans = 10*ans;
		}
		else if(cont != 0 && s[i] == '0'){
			ans = 10*ans + cont;
			cont = 0;
		}
		else cont++;
	}
	ans = 10*ans + cont;
	cout << ans << endl;
}
