#include <bits/stdc++.h>

using namespace std;

int bit[31][112345];

void init(int n){
	for(int i=1; i<=n; i++){
		for(int j=0; j<31; j++){
			bit[j][i] = 0;
		}
	}
}

void update(int b, int idx, int val, int n){
	for(int i = idx; i <= n; i += i&-i){
		bit[b][i]+=val;
	}
}

int query(int b, int idx){
	int ans = 0;
	for(int i=idx; i>0; i -= i&-i){
		ans += bit[b][i];
	}
	return ans;
}

int range_query(int b, int l, int r){
	return query(b, r) - query(b, l-1);
}



int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
	int n,q;
	cin >> n >> q;
	init(n);
	for(int i=1; i <= n; i++){
		int x;
		cin >> x;
		for(int j = 0; j<31; j++){
			if((1<<j) & x) update(j, i, 1, n);
		}
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		int ans = 0;
		for(int j=0; j<31; j++){
			if(range_query(j, l, r) <= (r-l)/2) ans |= (1<<j);
		}
		cout << ans << endl;
	}
}
