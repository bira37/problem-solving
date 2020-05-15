#include <bits/stdc++.h>

using namespace std;


int uf[200000+1];
int sz[200000+1];

void init(int n){
	for(int i=1; i<=n; i++){
		sz[i] = 1;
		uf[i] = i;
	}
}

int find(int a){
	if(uf[a] == a) return a;
	else {
		uf[a] = find(uf[a]);
		return uf[a];
	}
}

void merge(int x, int y){
	int a = find(x);
	int b = find(y);
	if(sz[a] < sz[b]) swap(a,b); 
	uf[b] = a;
	sz[a] += sz[b];
}

struct edges{
	int u,v,cost;
};

bool cmp(const edges & a, const edges & b){
	return (a.cost < b.cost);
}

int kruskal(vector<edges> & e){
	int ans = 0;
	sort(e.begin(), e.end(), cmp);
	for(int i = 0; i < e.size(); ++i){
		if(find(e[i].u) == find(e[i].v)) continue;
		merge(e[i].u, e[i].v);
		ans += e[i].cost;
		//cout << "union " << e[i].u << " " << e[i].v << " " << e[i].cost << endl;
	}
	return ans;
}

int main(){
	int n,m;

	while(cin >> n >> m, n + m !=0){
		vector<edges> v(m);
		init(n);

		int res = 0;

		for(int i=0; i<m; i++){
			cin >> v[i].u >> v[i].v >> v[i].cost;
			v[i].u++;
			v[i].v++;
			res += v[i].cost;
		}
		
		cout << res - kruskal(v) << endl;
	}
}
		
	
