#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(){
	int n;
	while(cin >> n, n!=0){
		string dna;
		set <string> arvore;
		for(int i=0; i < n; i++){
			cin >> dna;
			sort(dna.begin(),dna.end());
			arvore.insert(dna);
		}
		
		cout << arvore.size() << endl;
	}
	return 0;
}
			
		
			

