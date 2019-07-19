#include <bits/stdc++.h>

using namespace std;

int bit[10000+1];
int bit2[10000+1];

void init(int n){
	for(int i=1; i<=n; i++){
		bit[i] = 0;
		bit2[i] = 0;
	}
}

//auxiliar
void update(int *bit, int idx, int val, int n){
	for(int i = idx; i <= n; i += i&-i){
		bit[i]+=val;
	}
}

//auxiliar
int query(int *bit, int idx){
	int ans = 0;
	for(int i=idx; i>0; i -= i&-i){
		ans += bit[i];
	}
	return ans;
}

void range_update(int l, int r, int val, int n){
	update(bit, l, val, n);
	update(bit, r+1, -val, n);
	update(bit2, l, val*(l-1), n);
	update(bit2, r+1, -val*r, n);
}

int prefix_query(int idx){
	return query(bit,idx)*idx - query(bit2, idx);
}

int range_query(int l, int r){
	return prefix_query(r) - prefix_query(l-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,u;
		cin >> n >> u;
		init(n);
		for(int i=0; i<u; i++){
			int x,y,val;
			cin >> x >> y >> val;
			x++, y++;
			range_update(x,y,val,n);
		}
		int q;
		cin >> q;
		while(q--){
			int c;
			cin >> c;
			c++;
			cout << range_query(c,c) << endl;
		}
	}
}


