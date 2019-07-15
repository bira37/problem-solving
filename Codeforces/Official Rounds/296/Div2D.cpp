#include <bits/stdc++.h>
#define int long long
using namespace std;

struct vertex{
	int p, w;
};

bool cmp(const vertex & a, const vertex & b){
	return a.p + a.w < b.p + b.w;
}

int32_t main(){
	int n;
	cin >> n;
	vertex v[n];
	for(int i=0; i<n; i++){
		cin >> v[i].p >> v[i].w;
	}
	sort(v, v+n, cmp);

	
	int ans = 1;
	int curr = 0;
	
	for(int i=1; i<n; i++){
		if(v[i].p - v[curr].p >= v[i].w + v[curr].w){
			ans++;
			curr = i;
		}
	}
	
	cout << ans << endl;
}