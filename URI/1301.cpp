#include <bits/stdc++.h>

using namespace std;

int bit[112345];
int bit2[112345];
int bitz[112345];
int bitz2[112345];

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

void initz(int n){
	for(int i=1; i<=n; i++){
		bitz[i] = 0;
		bitz2[i] = 0;
	}
}

void range_updateZ(int l, int r, int val, int n){
	update(bitz, l, val, n);
	update(bitz, r+1, -val, n);
	update(bitz2, l, val*(l-1), n);
	update(bitz2, r+1, -val*r, n);
}

int prefix_queryZ(int idx){
	return query(bitz,idx)*idx - query(bitz2, idx);
}

int range_queryZ(int l, int r){
	return prefix_queryZ(r) - prefix_queryZ(l-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n,k;
	while(cin >> n >> k){
		int v[n+1];
		init(n);
		initz(n);
		for(int i=1; i<=n; i++){
			cin >> v[i];
			if(v[i] < 0){
				range_update(i,i,1,n);
			}
			else if(v[i] == 0) range_updateZ(i,i,1,n);
		}
		for(int i=0; i<k; i++){
			char c;
			cin >> c;
			if(c == 'C'){
				int x,val;
				cin >> x >> val;
				if(v[x] > 0 && val < 0){
					range_update(x,x,1,n);
				}
				else if(v[x] < 0 && val > 0){
					range_update(x,x,-1,n);
				}
				if(v[x] == 0 && val != 0) range_updateZ(x,x,-1,n);
				else if(v[x] != 0 && val == 0) range_updateZ(x,x,1,n);
				v[x] = val;
			}
			else if(c == 'P'){
				int x,y;
				cin >> x >> y;
				if(range_queryZ(x,y) > 0) cout << '0';
				else if(range_query(x,y) % 2) cout << '-';
				else cout << '+';
			}
		}
		cout << endl;
	}
}
		 
			
