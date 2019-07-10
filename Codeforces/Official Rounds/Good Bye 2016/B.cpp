#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int pos = 20000;
	bool flag = true;
	for(int i=0; i < n; i++){
		int km;
		string dir;
		cin >> km >> dir;
		if(!flag) continue;
		if(dir == "North") {
			if(pos + km > 20000) flag = false;
			else pos = pos+km;
		}
		else if(dir == "South"){
			if(pos - km < 0) flag = false;
			else pos = pos-km;
		}
		else if(pos == 20000 || pos == 0) flag = false;
	}
	
	if(pos != 20000) flag = false;
	
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
} 
