#include <bits/stdc++.h>
 
using namespace std;
 
bool cmp(const pair<int, int> & a, const pair<int, int> & b){
	return a.first < b.first || (a.first == b.first && a.second > b.second);
}
 
vector<int> adj[112345];
 
int main(){
	int n,m;
	cin >> n >> m;
	int degree[n+1], ans[n+1];
	for(int i=1; i<=n; i++){
		degree[i] = 0;
		adj[i].clear();
	}
	
	for(int i=0; i<m; i++){
		int u,v;
		cin >> u >> v;
		adj[v].push_back(u);
		degree[u]++;
	}
	
	set< pair<int, int>, bool(*)(const pair<int, int> & a, const pair<int, int> & b) > s(&cmp);
	s.clear();
	
	for(int i=1; i<=n; i++){
		s.insert(make_pair(degree[i], i));
	}
	
	for(int i = n; i>0; i--){
		//cout << "Set" << endl;
		//for(pair<int, int> x: s){
		//	cout << "vertice " << x.second << " grau " << x.first << endl;
		//}
		//cout << "#######################" << endl;
		pair<int, int> curr = *s.begin();
		//cout << "Current" << endl;
		//cout << "vertice " << curr.second << " grau " << curr.first << endl;
		s.erase(s.begin());
		ans[curr.second] = i;
		for(int i=0; i<adj[curr.second].size(); i++){
			int v = adj[curr.second][i];
			pair<int, int> val;
			val = *s.find(make_pair(degree[v], v));
			s.erase(make_pair(degree[v], v));
			//cout << "Pre update" << endl;
			//cout << "vertice " << val.second << " grau " << val.first << endl;
			val.first--;
			degree[val.second]--;
			//cout << "Post update" << endl;
			//cout << "vertice " << val.second << " grau " << val.first << endl;
			s.insert(val);
		}
	}
	
	for(int i=1; i<=n; i++){
		if(i>1) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
	
