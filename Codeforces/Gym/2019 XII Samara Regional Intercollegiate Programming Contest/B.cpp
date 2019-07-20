#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string mat[2];
	cin >> mat[0] >> mat[1];
	int n = mat[0].size();
	int bot = 0, top = 0, all = 0, nothing = 0;
	for(int i=0; i<n; i++){
		if(mat[0][i] == '#' && mat[1][i] == '#') all++;
		else if(mat[0][i] == '#') top++;
		else if(mat[1][i] == '#') bot++;
		else nothing++;
	}
	if(bot > 0 && top > 0 && all == 0){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	int i = 0;
	while(nothing > 0){
		mat[0][i] = '.';
		mat[1][i] = '.';
		nothing--;
		i++;
	}
	while(bot > 0){
		mat[0][i] = '.';
		mat[1][i] = '#';
		bot--;
		i++;
	}
	while(all > 0){
		mat[0][i] = '#';
		mat[1][i] = '#';
		all--;
		i++;
	}
	while(top > 0){
		mat[0][i] = '#';
		mat[1][i] = '.';
		top--;
		i++;
	}
	for(int i=0; i<2; i++){
		for(int j=0; j<n; j++) cout << mat[i][j];
		cout << endl;
	}
}
