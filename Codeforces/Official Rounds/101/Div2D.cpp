#include <bits/stdc++.h>
#define int long long
using namespace std;

struct ramp{
	int x,d,t,p, id;
	ramp() {}
	ramp(int x, int d, int t, int p, int id) : x(x), d(d), t(t), p(p), id(id) {}
};

struct info{
	int v,d,id;
	info(){}
	info(int v, int d, int id) : v(v), d(d), id(id) {}
};

bool operator<(const info & a, const info & b){
	return !(a.d <= b.d);
}

vector<int> d;
vector<int> p;
vector<int> val;
vector< vector<info> > adj;
vector<int> comp;
set<int> tmp;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, l;
	cin >> n >> l;
	ramp v[n];
	for(int i=0; i<n; i++){
		cin >> v[i].x >> v[i].d >> v[i].t >> v[i].p;
		v[i].id = i+1;
		if(v[i].x - v[i].p < 0) continue;
		tmp.insert(v[i].x - v[i].p);
		tmp.insert(v[i].x + v[i].d);
	}

	tmp.insert(0);
	tmp.insert(l);

	for(int x : tmp) if(x >= 0 ) comp.push_back(x);

	d.resize(comp.size());
	p.resize(comp.size());
	val.resize(comp.size());
	adj.resize(comp.size());
	for(int i=0; i<comp.size(); i++){
		d[i] = (int)1e15;
	}

	//for(int i=0; i<comp.size(); i++) cout << comp[i] << " ";
	//cout << endl;

	for(int i=0; i<comp.size()-1; i++){
		adj[i].push_back(info(i+1, abs(comp[i] - comp[i+1]), 0));
		adj[i+1].push_back(info(i, abs(comp[i] - comp[i+1]), 0));
	}

	for(int i=0; i<n; i++){
		if(v[i].x - v[i].p < 0) continue;
		int a = lower_bound(comp.begin(), comp.end(), v[i].x - v[i].p) - comp.begin();
		int b = lower_bound(comp.begin(), comp.end(), v[i].x + v[i].d) - comp.begin();
		adj[a].push_back(info(b, v[i].t + v[i].p, v[i].id));
	}

	priority_queue<info> pq;
	pq.push(info(0, 0, 0));
	d[0] = 0;
	//shortest fucking path 
	while(!pq.empty()){
		info u = pq.top();
		pq.pop();
		if(d[u.v] != u.d) continue;
		//cout << "at " << comp[u.v] << " with " << u.d << endl;
		for(int i=0; i<adj[u.v].size(); i++){
			int w = adj[u.v][i].v;
			//cout << comp[w] << " " << d[w] << " vs " << u.d + adj[u.v][i].d << endl;
			if(d[w] <= u.d + adj[u.v][i].d) continue;
			d[w] = u.d + adj[u.v][i].d;
			p[w] = u.v;
			val[w] = adj[u.v][i].id;
			pq.push(info(w, d[w], 0));
		}
	}

	cout << d[comp.size()-1] << endl;
	
	vector<int> ans;
	int curr = comp.size()-1;
	while(curr != 0){
		if(val[curr] != 0) ans.push_back(val[curr]);
		curr = p[curr];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++){
		if(i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

