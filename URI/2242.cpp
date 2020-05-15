#include <bits/stdc++.h>

using namespace std;

int main(){
	string x,y;
	string c;
	cin >> c;
	for(int i=0, len = c.size(); i< len; i++){
		if(c[i] == 'a' || c[i]== 'e' || c[i]== 'i' || c[i]== 'o' || c[i]== 'u') x+=c[i];
	}
	y = x;
	reverse(x.begin(), x.end());
	if(x==y) cout << 'S' << endl;
	else cout << 'N' << endl;
}
