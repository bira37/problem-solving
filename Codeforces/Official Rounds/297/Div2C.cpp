#include <bits/stdc++.h>
#define int long long
using namespace std;

int cnt[1123456];
bool transformedone[1123456];

int32_t main(){
	int n;
	cin >> n;
	int ans = 0;
	set< int, greater<int> > s;
	for(int i=0; i<1123456; i++){
		cnt[i] = 0;
		transformedone[i] = false;
	}
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		s.insert(x);
		cnt[x]++;
	}
	vector<int> v;
	for(int x : s){
		if(cnt[x]%2 && !(cnt[x] == 1 && transformedone[x])){
			cnt[x-1]++;
			transformedone[x-1] = true;
			cnt[x]--;
		}
		if(cnt[x] >= 2) v.push_back(x);
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int i=0; i<v.size(); i++){
		while(cnt[v[i]] >= 4){
			ans += v[i]*v[i];
			cnt[v[i]]-=4;
		}
		if(cnt[v[i]] == 2 && i+1 < v.size()){
			ans += v[i]*v[i+1];
			cnt[v[i]]-=2;
			cnt[v[i+1]]-=2;
		}
	}
	cout << ans << endl;
}
	