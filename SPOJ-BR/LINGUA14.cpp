#include <bits/stdc++.h>

using namespace std;

int main(){
	string x;
	char c;
	bool flag = false;
	while(cin >> x, c = getchar()){
		if(!flag) flag = true;
		else cout << " ";
		for(int i=0; i<x.size(); i++) if(i%2) cout << x[i];
		if(c == '\n') break;
	}
	cout << endl;
}

