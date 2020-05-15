#include <bits/stdc++.h>

#define ff first
#define ss second
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define pii pair<int, int>
#define pll pair<ll,ll> 
#define IOS_SYNC ios_base::sync_with_stdio
#define vi vector<int>
#define vll vector<ll>
#define vpll vector< pll >
#define vpii vector< pii >

using namespace std;

typedef long long ll;

////////////////////////CODE//////////////////////////////////////////////////////


int uf[100001];
int sz[100001];
int pt[100001];

int create_set(int n, int *v){
	for(int i=1; i<=n; i++){
		uf[i] = i;
		sz[i] = 1;
		pt[i] = v[i-1];
	}
}

int find_set(int u){
	if(uf[u] == u) return u;
	else return uf[u] = find_set(uf[u]);
}

void union_set(int u, int v){
	int a = find_set(u);
	int b = find_set(v);
	if(a == b) return;
	
	if(sz[a] < sz[b]) swap(a,b);
	
	uf[b] = a;
	sz[a] += sz[b];
	pt[a] += pt[b];
}

int main(){
	IOS_SYNC(false);
	int n,q;
	while(cin >> n >> q, n | q){
		int vec[n];
		for(int i=0; i<n; i++) cin >> vec[i];
		create_set(n,vec);

		int curr = 1;
		int victory = 0;
		while(q--){
			int act, u,v;
			cin >> act >> u >> v;
			if(act == 1){
				union_set(u,v);
			}
			else {
				int a = find_set(u);
				int b = find_set(v);
				curr = find_set(curr);
				//cout << pt[a] << " " << pt[b] << endl;
				if(pt[a] > pt[b] && curr == a) victory++;
				else if(pt[b] > pt[a] && curr == b) victory++;
			}
		}
		cout << victory << endl;
	}
	return 0;
}
