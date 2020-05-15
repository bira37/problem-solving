#include <bits/stdc++.h>

using namespace std;

int main(){
	string x;
	while(cin >> x){
		for(int i=0; i<x.size(); i++){
			for(int j=0; j<i; j++) cout << " ";
			for(int j=0; j<x.size()-i; j++){
				if(!j) cout << x[j];
				else cout << " " << x[j];
			}
			cout << endl;
		}
		cout << endl;
	}
}
