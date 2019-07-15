#include <bits/stdc++.h>
#define int long long
using namespace std;

struct in{
	int grad,ess;
};

bool cmp(const in & a, const in & b){
	return a.ess < b.ess;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,r,avg;
	cin >> n >> r >> avg;
	avg *= n;
	in v[n];
	int tot = 0;
	for(int i=0; i<n; i++){
		cin >> v[i].grad >> v[i].ess;
		tot += v[i].grad;
	}
	
	sort(v, v+n, cmp);
	
	int ans = 0;
	
	for(int i=0; i<n; i++){
		if(tot >= avg) break;
		
		int increase = r - v[i].grad;
		int used = min(avg - tot, increase);
		ans += v[i].ess*used;
		tot += used;
	}
	
	cout << ans << endl;	
}