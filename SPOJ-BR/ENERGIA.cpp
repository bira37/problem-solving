#include <iostream>

using namespace std;

int uf[100],sz[100];

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
	int e,l,teste=0;
	while (cin >> e >> l, e+l != 0){
		init(e);
		int x,y;
		int resp=e;
		for(int i=0; i<l; i++){
			cin >> x >> y;
			if(find(x) != find(y)){
				merge(x,y);
				resp--;
			}
		}
		cout << "Teste " << ++teste << endl;
		if(resp==1) cout << "normal" << endl;
		else cout << "falha" << endl;
	}
}

