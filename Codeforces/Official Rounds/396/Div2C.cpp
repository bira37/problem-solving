#include <bits/stdc++.h>
 
using namespace std;
 
string x;
int size[26];
int n;
long long dp[1002];
 
long long calculate(int i){
	int menor = 0x3f3f3f;
	if(dp[i] != -1) return dp[i];
	else {
		int q = 0;
		for(int j=i; j<n; j++){
			menor = min(menor, size[x[j]-'a']);
			if(j-i+1<=menor) q = (q + calculate(j+1)%1000000007)%1000000007;
		}
		dp[i] = q;
		return dp[i];	
	}
}
 
int main(){
	
	cin >> n;
	for(int i=0; i<n+1; i++){
		dp[i] = -1;
	}
	dp[n] = 1;
	cin >> x;
	for(int i=0; i<26; i++){
		cin >> size[i];
	}
	
	cout << calculate(0) << endl;
 
	int ans2=0, ans3=1;
	
	int menor;
	for(int i=0; i<n; i++){
		menor = 0x3f3f3f3f;
		for(int j=i; j<n; j++){
			menor = min(menor, size[x[j]-'a']);
			if(j-i+1 <= menor) ans2 = max(ans2, j-i+1);
			else break;
		}
	}
 
	cout << ans2 << endl;
 
	for(int i=0; i<n; i++){
		menor = 0x3f3f3f3f;
		for(int j=i; j<n; j++){
			menor = min(menor, size[x[j]-'a']);
			if(j-i+1 > menor){
				ans3++;
				i = j-1;
				break;
			}
		}
	}
 
	cout << ans3 << endl;
}
		
