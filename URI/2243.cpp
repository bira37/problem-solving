#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int vet[n];
	int pre[n],pos[n];
	for(int i=0; i<n; i++){
		cin >> vet[i];
	}
	pre[0] = 1;
	for(int i=1; i<n; i++){
		pre[i] = min(pre[i-1]+1,vet[i]);
	}
	pos[n-1]=1;
	for(int i=n-2; i>=0; i--){
		pos[i] = min(pos[i+1]+1,vet[i]);
	}
	int res = 1;
	for(int i=0; i<n; i++){
		res = max(res, min(pre[i],pos[i]));
	}
	cout << res << endl;
}
