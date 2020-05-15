#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;	
	while(cin >> n){
		bool flag = false;
		for(int i=0, len = sqrt(n); i<=len && !flag; i++){
			int resto = n - i*i;
			int raiz = sqrt(resto);
			if(raiz*raiz == resto){
				cout << "YES" << endl;
				flag = true;
			}
		} 
		if(!flag) cout << "NO" << endl;
	}
}
