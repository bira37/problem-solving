#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i=1; i<=n; i++){
		bool ok = true;
		for(int j=1; j<=n; j++){
			int x;
			cin >> x;
			if(x == 1 || x == 3) ok = false;
		}
		if(ok) v.push_back(i);
	}
	cout << v.size() << endl;
	for(int i=0; i<v.size(); i++) cout << v[i] << " ";
	if(v.size() > 0) cout << endl;
}
