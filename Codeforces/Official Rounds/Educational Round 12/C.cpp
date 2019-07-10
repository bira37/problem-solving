#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	
	string x;
	cin >> x;
	int dp[x.size()];
 
	for(int i=0; i<x.size(); i++){
		dp[i] = 0;
	}
	if(x[0] == x[1]) dp[0]++;
	if(x[x.size()-1] == x[x.size()-2]) dp[x.size()-1]++;
	
	for(int i=1; i<x.size()-1; i++){
		if(x[i] == x[i-1]) dp[i]++;
		if(x[i] == x[i+1]) dp[i]++;
	}
 
	//for(int i=0; i<x.size(); i++) cout << dp[i] << " ";
	//cout << endl;
 
	for(int i=1; i<x.size()-1; i++){
		if(dp[i] == 2){
			for(int j=0; j<26; j++){
				if(x[i-1] != 'a'+j && x[i+1] != 'a'+j){
					x[i] = 'a'+j;
					dp[i]-=2;
					dp[i-1]--;
					dp[i+1]--;
					break;
				}
			}
		}
	}
 
	//for(int i=0; i<x.size(); i++) cout << dp[i] << " ";
	//cout << endl;
 
	for(int i=1; i<x.size()-1; i++){
		if(dp[i] == 1){
			if(x[i] == x[i-1]) dp[i-1]--;
			else dp[i+1]--;
			dp[i]--;
			for(int j=0; j<26; j++){
				if(x[i-1] != 'a'+j && x[i+1] != 'a'+j){
					x[i] = 'a'+j;
					break;
				}
			}
		}
	}
	if(x.size() == 2 && x[0] == x[1]){
		if(x[0] == 'a') cout << x[0] << 'b' << endl;
		else cout << x[0] << 'a' << endl;
	}
	else cout << x << endl;
}
