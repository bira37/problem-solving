#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<string, int> pol;
	pol["Tetrahedron"] = 4;
	pol["Cube"] = 6;
	pol["Octahedron"] = 8;
	pol["Dodecahedron"] = 12;
	pol["Icosahedron"] = 20;
	int n;
	cin >> n;
	int ans = 0;
	for(int i=0; i<n; i++){
		string x;
		cin >> x;
		ans+= pol[x];
	}
 
	cout << ans << endl;
}
