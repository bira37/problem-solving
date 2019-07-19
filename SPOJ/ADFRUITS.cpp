#include <bits/stdc++.h>

using namespace std;

int main(){
	string a,b;
	while(cin >> a >> b){
		int dp[a.size()+1][b.size()+1];
		
		for(int i=0; i<=a.size(); i++){
			for(int j=0; j<=b.size(); j++) dp[i][j] = 0;
		}
	
		for(int i=1; i<=a.size(); i++){
			for(int j=1; j<=b.size(); j++){
				if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		
		vector<char> lcs;
		int i = a.size();
		int j = b.size();
		while(i > 0 && j > 0){
			if(a[i-1] == b[j-1]){
				lcs.push_back(a[i-1]);
				i--;
				j--;
			}
			else if(dp[i-1][j] > dp[i][j-1]){
				i--;
			}
			else j--;
		}
		reverse(lcs.begin(), lcs.end());
		//for(int i=0; i<lcs.size(); i++) cout << lcs[i];
		//cout << endl;
		string dp2[lcs.size()+1];
		string aux = "";
		int pointer = 0;
		for(int i=0; i<a.size(); i++){
			if(pointer == lcs.size()) aux+=a[i];
			else if(a[i] != lcs[pointer]) aux+=a[i];
			else if(a[i] == lcs[pointer]){
				dp2[pointer] = aux;
				aux = "";
				pointer++;
			}
		}
		dp2[pointer] = aux;
		//for(int i=0; i<= lcs.size(); i++) cout << dp2[i] << endl;
		string dp3[lcs.size()+1];
		aux = "";
		pointer = 0;
		for(int i=0; i<b.size(); i++){
			if(pointer == lcs.size()) aux+=b[i];
			else if(b[i] != lcs[pointer]) aux+=b[i];
			else if(b[i] == lcs[pointer]){
				dp3[pointer] += aux;
				aux = "";
				pointer++;
			}
		}
		dp3[pointer] += aux;
		//for(int i=0; i<= lcs.size(); i++) cout << dp3[i] << endl;
		for(int i=0 ; i<lcs.size(); i++) cout << dp2[i] << dp3[i] << lcs[i];
		cout << dp2[lcs.size()] << dp3[lcs.size()];
		cout << endl;
		
	}
}

