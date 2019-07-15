#include <bits/stdc++.h>

using namespace std;

int main(){
	int t1, t2, t, d;
	cin >> t1 >> t2 >> t >> d;
	if(d == 0){
		cout << t1*t << endl;
		return 0;
	}
	int ans = t1;
	int cur = t1;
	for(int i=1; i<t; i++){
		bool ok = false;
		for(int j = d; j>=0; j--){
			if((abs((cur+j) - t2) + (d-1))/d <= (t - i -1)){
				cur += j;
				ans += cur;
				ok = true;
				break;
			}
		}
		if(!ok){
			for(int j = 0; j<= d; j++){
				if((abs((cur-j) - t2) + (d-1))/d <= (t - i -1)){
					cur -= j;
					cur = max(cur, t2);
					ans += cur;
					break;
				}
			}
		}
		//cout << "cur " << cur << endl;
	}
	cout << ans << endl;
}
	