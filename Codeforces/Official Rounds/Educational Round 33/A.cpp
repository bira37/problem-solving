#include <bits/stdc++.h>

using namespace std;

int n;
int v[1123];

bool solve(int i, int j1, int j2, int spec){
	if(i == n) return true;
	bool flag = false;
	if(j1 == v[i]){
		flag |= solve(i+1, j1, spec, j2);
	}
	else if(j2 == v[i]){
		flag |= solve(i+1, j2, spec, j1);
	}
	else{
		flag = false;
	}
	return flag;
}

int main(){
	 cin >> n;
	 for(int i=0; i<n; i++){
	 	cin >> v[i];
	 }
	 bool flag = false;
	 flag |= solve(0, 1, 2, 3);
	 if(flag) cout << "YES" << endl;
	 else cout << "NO" << endl;
}