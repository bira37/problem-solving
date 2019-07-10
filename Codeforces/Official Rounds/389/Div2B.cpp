#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int contains[27];
	bool correct[27];
	for(int i=0; i<27; i++){
		contains[i] = 0;
		correct[i] = false;
	}
	ios_base::sync_with_stdio(false);
	string certa,errada;
	cin >> certa >> errada;
	set< pair<char, char> > letter;
	vector< pair<char, char> > vis;
	for(int i=0, len = certa.size(); i<len; i++){
		if(certa[i] != errada[i]){
			pair<char, char> aux = make_pair(certa[i], errada[i]);
			pair<char, char> aux2 = make_pair(errada[i], certa[i]);
			if(!letter.count(aux) && !letter.count(aux2)){
				letter.insert(make_pair(errada[i], certa[i]));
				contains[certa[i]-97]++;
				contains[errada[i]-97]++;
			}
		}
		else correct[certa[i]-97] = true;
	}
 
	for(int i=0; i<27; i++){
		if(contains[i] > 1 || (correct[i] && contains[i] == 1)){
			cout << -1 << endl;
			return 0;
		}
	}
 
	cout << letter.size() << endl;
 
	for(pair<char, char> x : letter){
		cout << x.first << " " << x.second << endl;
	}
}
