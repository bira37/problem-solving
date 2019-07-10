#include <bits/stdc++.h>
#define endl '\n'
 
using namespace std;
 
int uf[312345];
int sz[312345];
 
ifstream fin("connect.in");
ofstream fout("connect.out");
 
struct event{
	int op, u, v, l, r;
	event() {}
	event(int o, int a, int b, int x, int y) : op(o), u(a), v(b), l(x), r(y) {}
};
 
map< pair<int, int>, int > edge_to_l;
stack< pair<int*,int> > hist;
vector<event> events;
 
int init(int n){
	for(int i=0; i<=n; i++){
		uf[i] = i;
		sz[i] = 1;
	}
}
 
int find(int u){
	if(uf[u] == u) return u;
	else return find(uf[u]);
}
 
void merge(int u, int v){
	int a = find(u);
	int b = find(v);
	if(a == b) return;
	if(sz[a] < sz[b]){
		hist.push(make_pair(&uf[a], uf[a]));
		uf[a] = b;
		hist.push(make_pair(&sz[b], sz[b]));
		sz[b]+= sz[a];
	}
	else {
		hist.push(make_pair(&uf[b], uf[b]));
		hist.push(make_pair(&sz[a], sz[a]));
		uf[b] = a;
		sz[a]+=sz[b];
	}
}
 
int snap(){
	return hist.size();
}
 
void rollback(int t){
	while(hist.size() > t){
		pair<int*, int> aux = hist.top();
		hist.pop();
		*aux.first = aux.second;
	}
}
 
void solve(int l, int r, int comp){
	int cnt;
	if(l == r){
		if(events[l].op == 2){
			fout << comp << endl;
		}
		return;
	}
	
	int m = (l+r)/2;
	//doing for [L,m]
	cnt = 0;
	int t = snap();
	for(int i=l; i<=r; i++){
		if(events[i].op == 0 || events[i].op == 1){
			if(events[i].l <= l && m <= events[i].r && find(events[i].u) != find(events[i].v)){
				merge(events[i].u, events[i].v);
				cnt++;
			}
		}
	}
	solve(l, m, comp-cnt);
	rollback(t);
	
	//doing for [m+1, R]
	cnt = 0;
	t = snap();
	for(int i=l; i<=r; i++){
		if(events[i].op == 0 || events[i].op == 1){
			if(events[i].l <= m+1 && r <= events[i].r && find(events[i].u) != find(events[i].v)){
				merge(events[i].u, events[i].v);
				cnt++;
			}
		}
	}
	solve(m+1, r, comp-cnt);
	rollback(t);
}
 
void offline_process(){
	int n, q;
	fin >> n >> q; //number of vertex and queries
	init(n);
	for(int i=0; i<q; i++){
		char op;
		int u,v;
		fin >> op; //add, remove or query for u,v
		if(op == '+'){
			fin >> u >> v;
			if(u > v) swap(u,v);
			events.push_back(event(0, u, v, i, -1));
			edge_to_l[make_pair(u,v)] = i;
		}
		else if(op == '-'){
			fin >> u >> v;
			if(u > v) swap(u,v);
			int l = edge_to_l[make_pair(u,v)];
			events.push_back(event(1, u, v, l, i));
			events[l].r = i;
		}
		else if(op == '?'){
			events.push_back(event(2, -1, -1, -1, -1));
		}
	}
	for(int i=0; i<q; i++){
		if(events[i].op == 0){
			if(events[i].r == -1){
				events[i].r = events.size();
				events.push_back(event(1, events[i].u, events[i].v, events[i].l, events[i].r));
			}
		}
	}
	if(events.size() == 0) return;
	solve(0, events.size()-1, n);
}
 
int main(){
	offline_process();
}
