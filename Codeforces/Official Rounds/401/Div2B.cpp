#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string sherlock,moriarty;
	cin >> sherlock;
	cin >> moriarty;
	int m[10];
	int s[10];
	int cm[10];
	int cs[10];
	for(int i=0; i<10; i++){
		m[i] = 0;
		s[i] = 0;
		cm[i] = 0;
		cs[i] = 0;
	}
	
	for(int i=0; i<n; i++){
		m[moriarty[i] - '0']++;
		cm[moriarty[i] - '0']++;
		s[sherlock[i] - '0']++;
		cs[sherlock[i] - '0']++;
	}
 
	int i = 0;
	int ans = 0;
	while(i < 10){
		if(s[i] == 0){
			i++;
			continue;
		}
		while(s[i] > 0){
			int j = i;
			while(j < 10 && m[j] == 0) j++;
			if(j < 10){
				s[i]--;
				m[j]--;
				ans++;
			}
			else goto bye;
		}
	}
bye:    cout << n - ans << endl;
 
	i = 0;
	ans = 0;
	while(i < 10){
		if(cs[i] == 0){
			i++;
			continue;
		}
		while(cs[i] > 0){
			int j = i+1;
			while(j < 10 && cm[j] == 0) j++;
			if(j < 10){
				cs[i]--;
				cm[j]--;
				ans++;
			}
			else goto bye2;
		}
	}
bye2:   cout << ans << endl;
}
