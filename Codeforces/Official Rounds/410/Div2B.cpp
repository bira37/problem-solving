#include <bits/stdc++.h>
 
using namespace std;
vector< map<string, int> > change;
 
void make_map(string s){
	map<string, int> aux;
	change.push_back(aux);
	int atual = change.size()-1;
	change[atual][s] = 0;
	for(int i=0; i<s.size()-1; i++){
		char x = s[0];
		s.erase(s.begin());
		s.push_back(x);
		if(!change[atual].count(s)) change[atual][s] = i+1;
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string v[n];
	for(int i=0; i<n; i++){
		cin >> v[i];
		make_map(v[i]);
	}
	
	int ans = 0x3f3f3f3f;
	for(int i=0; i<n; i++){
		int cont = 0;
		for(int j=0; j<n; j++){
			if(change[j].count(v[i])) cont += change[j][v[i]];
			else {
				cout << -1 << endl;
				return 0;
			}
		}
		ans = min(cont, ans);
	}
 
	cout << ans << endl;
}
