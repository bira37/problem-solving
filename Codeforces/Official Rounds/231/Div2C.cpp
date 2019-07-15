#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	int cnt11 = 0, cnt00 = 0, cnt10 = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			string s;
			cin >> s;
			if(s == "11") cnt11++;
			else if(s == "00") cnt00++;
			else cnt10++;
		}
	}
	string ans[n][m];
	int av[m];
	for(int i=0; i<m; i++) av[i] = 0;
	int p = 0;
	while(cnt11){
		if(av[p] < n){
			cnt11--;
			ans[av[p]][p] = "11";
			av[p]++;
		}
		p++;
		p%=m;
	}
	p = 0;
	while(cnt00){
		if(av[p] < n){
			cnt00--;
			ans[av[p]][p] = "00";
			av[p]++;
		}
		p++;
		p%=m;
	}
	for(int i=0; i<m; i++){
		bool turn = false;
		while(av[i] < n){
			if(turn) ans[av[i]][i] = "01";
			else ans[av[i]][i] = "10";
			av[i]++;
			turn = !turn;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(j) cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}
}
	