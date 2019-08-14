#include <bits/stdc++.h>

using namespace std;

struct edges{
	int u,v,cost;
};

int uf[1123];
int sz[1123];

void init(int n){
	for(int i=1; i <= n; i++){
		sz[i]=1;
		uf[i]=i;
	}
}

int find(int n){
	if(uf[n]==n) return n;
	else return find(uf[n]);
}

void unit(int x, int y){
	int a=find(x);
	int b=find(y);
	if(sz[a] > sz[b]) swap(a,b);
	uf[a]=b;
	sz[b]+=sz[a];
}

bool cmp(const edges a, const edges b){
	if(a.cost < b.cost) return true;
	return false;
}

int calculaMST(edges *e, int s){
  int ans = 0;
	sort(e, e+s, cmp); //cmp ordena pelo custo
	for(int i=0; i < s; i++){
		if(find(e[i].u) == find(e[i].v)) continue;
		unit(e[i].u,e[i].v);
		if(e[i].v < e[i].u) swap(e[i].u, e[i].v);
		ans += e[i].cost;
	}
	return ans;
}

int main(){
	int s,d;
	int test = 0;
	while(cin >> s >> d){
	  edges e[d];
	  init(s);
	  for(int i=0; i<d; i++){
		  cin >> e[i].u >> e[i].v >> e[i].cost;
	  }
	  cout << "Instancia " << ++test << endl;
	  cout << calculaMST(e,d) << endl;
	  cout << endl;
	}
	return 0;
}
