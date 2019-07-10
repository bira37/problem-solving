#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	set<int> s;
	int ans = 0;
	int need[n+1];
	int last = -1;
	for(int i=1; i<=n; i++){
		need[i] = -1;
	}
	for(int i=0; i<2*n; i++){
		string order;
		cin >> order;
		if(order == "add") {
			int x;
			cin >> x;
			s.insert(x);
			if(x > *s.begin()) need[*s.begin()] = i;
 
		}
		else {
			if(need[*s.begin()] > last){
				ans++;
				last = need[*s.begin()];
			}
			s.erase(s.begin());
		}
	}
	cout << ans << endl;
}
