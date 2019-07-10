#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
int fat[21];
 
void calculate_fat(){
	fat[0] = 1;
	for(int i=1; i<=20; i++) fat[i] = fat[i-1]*i;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	calculate_fat();
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		if(n == 1){
			cout << 1 << endl;
			continue;
		}
		int cnt[26];
		int imp = 0;
		for(int i=0; i<26; i++){
			cnt[i] = 0;
		}
		for(int i=0; i<n; i++){
			cnt[s[i]-'a']++;
		}
		for(int i=0; i<26; i++){
			if(cnt[i]%2) imp++;
			cnt[i]/=2;
		}
		if(imp != 0 && imp > 1) cout << 0 << endl;
		else {
			int dem = 1;
			int num = 0;
			for(int i=0; i<26; i++){
				//cout << dem << endl;
				dem*=fat[cnt[i]];
				num+=cnt[i];
			}
			cout << fat[num]/dem << endl;
		}
	}
}
