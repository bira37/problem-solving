#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int l=0,r=0;
	int array[n];
	vector< pair<int,int> > ans;
	for(int i=0; i<n; i++){
		cin >> array[i];
	}
	for(int i=0; i<n; i++){
		if(array[i] != 0){
			while(i-1 < n && array[i+1] == 0) i++;
			r = i;
			ans.push_back(make_pair(l+1,r+1));
			l= i+1;
			r = i+1;
		}
		else r++;
	}
	if(ans.size() == 0){
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	cout << ans.size() << endl;
	for(int i=0, len = ans.size(); i<len; i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}
