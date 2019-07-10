#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	int v[n];
	set<int> ans;
	for(int i=0; i<n; i++) cin >> v[i];
	sort(v, v+n);
	if(n == 1){
		cout << -1 << endl;
		return 0;
	}
	if(n == 2) {
		if((v[1] - v[0])%2 == 0){
			ans.insert(v[0] - (v[1] - v[0]));
			ans.insert(v[0] + (v[1] - v[0])/2);
			ans.insert(v[1] + (v[1] - v[0]));
			cout << ans.size() << endl;
			for(set<int>::iterator it = ans.begin(); it != ans.end(); it++){
				if(it == ans.begin()) cout << *it;
				else cout << " " << *it;
			}
			cout << endl;
		}
		else {
			ans.insert(v[0] - (v[1] - v[0]));
			ans.insert(v[1] + (v[1] - v[0]));
			cout << ans.size() << endl;
			for(set<int>::iterator it = ans.begin(); it != ans.end(); it++){
				if(it == ans.begin()) cout << *it;
				else cout << " " << *it;
			}
			cout << endl;
		}
		return 0;
	}
	
	set<int> dif;
	dif.insert(v[1] - v[0]);
	int cnt = 0;
	for(int i=2; i<n; i++) dif.insert(v[i] - v[i-1]);
 
	if(dif.size() > 2){
		cout << 0 << endl;
		return 0;
	}
 
	if(dif.size() == 2){
		int aux = *(dif.begin());
		for(int i=1; i<n; i++){
			if(aux != v[i] - v[i-1] && aux*2 == v[i] - v[i-1] && ans.size() == 0){
				ans.insert(v[i]-aux);
			}
			else if(aux != v[i] - v[i-1]){
				cout << 0 << endl;
				return 0;
			}
		}
		cout << ans.size() << endl;
		cout << *(ans.begin()) << endl;
		return 0;
	}
	ans.insert(v[0] - (v[1] - v[0]));
	ans.insert(v[n-1] + (v[1] - v[0]));
	cout << ans.size() << endl;
	for(set<int>::iterator it = ans.begin(); it != ans.end(); it++){
		if(it == ans.begin()) cout << *it;
		else cout << " " << *it;
	}
	cout << endl;
}
