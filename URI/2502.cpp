#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	while(cin >> n >> m){
		map<char, char> cifra;
	
		string troca, original;
		cin.ignore();
		getline(cin, troca);
		//cout << "string 1 eh " << troca << endl;

		getline(cin, original);
		//cout << "string 2 eh " << original << endl;

		for(int i=0; i<n; i++){

			if(troca[i] >= 'A' && troca[i] <= 'Z' && original[i] >= 'A' && original[i] <= 'Z'){
				cifra[original[i]+32] = troca[i]+32;
				cifra[original[i]] = troca[i];
				cifra[troca[i]+32] = original[i]+32;
				cifra[troca[i]] = original[i];
			}
			else if(troca[i] >= 'A' && troca[i] <= 'Z' && !(original[i] >= 'A' && original[i] <= 'Z')){
				cifra[original[i]] = (troca[i]+32);
				cifra[troca[i]] = original[i];
				cifra[troca[i]+32] = original[i];
			}
			else if(!(troca[i] >= 'A' && troca[i] <= 'Z') && original[i] >= 'A' && original[i] <= 'Z'){
				cifra[original[i]] = troca[i];
				cifra[original[i]+32] = troca[i];
				cifra[troca[i]] = (original[i]+32);
			}
			else {
				cifra[original[i]] = troca[i];
				cifra[troca[i]] = original[i];
			}

		}
		for(int i=0; i<m; i++){
			string ans;
			getline(cin, ans);
			//cout << "teste eh " << ans << endl;
			for(int j=0; j<ans.size(); j++){
				//cout << ans[j] << " " << cifra[ans[j]] << endl;
				if(!cifra.count(ans[j])){
					cout << ans[j];
					continue;
				}
				
				//ans[j] = cifra[ans[j]];
				
				cout << cifra[ans[j]];	
					
			}

			cout << endl;
		}
		cout << endl;
	}
}
		
