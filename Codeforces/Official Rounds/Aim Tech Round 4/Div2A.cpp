#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	set<char> s;
	string x;
	cin >> x;
	int k;
	cin >> k;
	int cont =0;
	for(int i=0; i<x.size(); i++){
		if(s.count(x[i])) cont++;
		s.insert(x[i]);
	}
	if(k <= s.size()) cout << 0 << endl;
	else if(k - s.size() <= cont) cout << min(cont, k - (int)s.size()) << endl;
	else cout << "impossible" << endl;
}
