#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int v[n];
	int tot = 0;
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	for(int i=0; i<n-1; i++){
		tot += abs(v[i] - v[i+1]);
	}
	vector<int> diff;
	for(int i=0; i<n-1; i++){
		int atual = abs(v[i]-v[i+1]);
		int novo = abs(v[i] + v[i+1]);
		diff.push_back(atual - novo);
	}
	sort(diff.begin(), diff.end());
	int cnt = 2;
	while(cnt--){
		if(diff.empty() || diff.back()<0) break;
		tot -= diff.back();
		diff.pop_back();
	}
	cout << tot << endl;
}
