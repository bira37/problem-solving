#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	long long int cnt[3] = {0,0,0};
	long long int ans = 0;
	for(char c: s){
		if(c < '0' || c > '9'){
			cnt[0]=cnt[1]=cnt[2]=0;
			continue;
		}
		int val = c - '0';
		int aux[3];
		for(int i=0; i<3; i++) aux[(i+val)%3] = cnt[i];
		for(int i=0; i<3; i++) cnt[i] = aux[i];
		cnt[val%3]++;
		ans += cnt[0];
		//cout << ans << endl;
	}
	cout << ans << endl;
}
