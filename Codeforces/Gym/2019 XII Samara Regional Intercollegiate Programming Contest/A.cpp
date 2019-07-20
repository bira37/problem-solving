#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int v[n];
	int ans[n];
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	int cur = 0;
	int block = n;
	int vals[n+1];
	for(int i=0; i<=n; i++) vals[i] = n;
	for(int i=n-1; i>=0; i--){
		if(v[i] < 0){
			int val = -v[i];
			block = min(block, vals[val]);
		}
		//cout << "block  = " << block << endl;
		ans[i] = block - i;
		if(v[i] > 0){
			int val = v[i];
			vals[val] = min(vals[val], i);
		}
	}
	for(int i=0; i<n; i++) cout << ans[i] << " ";
	cout << endl;
}
