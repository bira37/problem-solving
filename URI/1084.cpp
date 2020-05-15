#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	string v;
	while(cin >> n >> k, n + k !=0){
		cin >> v;
		vector<char> ans;
		int cont = 0;
		for(int i=0; i<n; i++){
			if(ans.size() == 0) ans.push_back(v[i]);
			else {
				while(ans.size() > 0 && ans.back() < v[i] && cont < k){
					ans.pop_back();
					cont++;
				}
				ans.push_back(v[i]);
			}
		}
		
		while(cont < k){
			cont++;
			ans.pop_back();
		}
		for(int i=0; i< ans.size(); i++) cout << ans[i];
		cout << endl;
	}

}
		
		
		
	
