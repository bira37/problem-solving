#include <iostream>

using namespace std;

int uf[100000],sz[100000];

void init(int n){
	for(int i=1; i <=n; i++){
		uf[i] = i;
		sz[i] = 1;
	}
}

int find(int u){
	if(uf[u]==u) return u;
	else return find(uf[u]);
}

void merge(int u, int v){
	int a = find(u);
	int b = find(v);
	if(sz[a] > sz[b]) swap(a,b);
	uf[a]=b;
	sz[b] += sz[a];
}

int main(){
	int n,m;
	char c;
	cin >> n >> m;
	init(n);
	for(int i=0; i < m; i++){
		int x,y;
		cin >> c >> x >> y;
		if(c == 'F') merge(x,y);
		else if(c == 'C'){
			if( find(x) == find(y) ) cout << 'S' << endl;
			else cout << 'N' << endl;
		}
	}
}

