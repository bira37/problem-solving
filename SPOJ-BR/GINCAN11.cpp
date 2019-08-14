#include <bits/stdc++.h>

using namespace std;
//para acessar o tamanho , sz[find(u)] , (u pode nao ser lider) 
const int N = 100000;
int uf[N];
int sz[N];

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
	if(sz[a] < sz[b]){
		uf[a]=b;
		sz[b] += sz[a];
	}
	else {
		uf[b]=a;
		sz[a]+= sz[b];
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	int resp=n;
	init(n);
	for(int i=0; i<m ; i++){
		int x,y;
		cin >> x >> y;
		if(find(x) != find(y)){
			merge(x,y);
			resp--;
		}
	}
	cout << resp << endl;
}



