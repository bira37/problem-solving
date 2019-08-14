#include <bits/stdc++.h>

using namespace std;

int main(){
	string par, impar;
	int n;
	int t = 0;
	while(cin >> n, n != 0){
		if(t != 0) cout << endl;
		
		cin >> par >> impar;
		cout << "Teste " << ++t << endl;
		for(int i=0; i<n; i++){
			int x,y;
			cin >> x >> y;
			if((x+y)%2) cout << impar << endl;
			else cout << par << endl;
		}
	}
}

