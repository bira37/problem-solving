#include <bits/stdc++.h>
#define ii pair<int, int>
#define ff first
#define ss second
#define M 1000000007
#define pb push_back
#define endl '\n'
using namespace std;

typedef long long ll;

int v[212345];

vector<int> adj[212345];
int p[212345];

int k = 2;
int n;

void solve(int u, int idx){
	if(idx == n+1) return;
	for(int i=0; i<v[idx]; i++){
		adj[u].push_back(k++);
	}
	solve(adj[u][0], idx+1);
}

bool check(int u){
	if(adj[u].size() == 0) return true;
	int v = adj[u][0];
	if(adj[v].size() > 1 && adj[u].size() > 1) return false;
	return check(v);
}

void dfs(int u){
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		p[v] = u;
		dfs(v);
	}
}

void rearrange(int u){
	int v = adj[u][0];
	if(adj[v].size() > 1 && adj[u].size() > 1){
		p[adj[v][1]] = adj[u][1];
		return;
	}
	else rearrange(v);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	int sum = 0;
	
	int check1 = 0;
	for(int i=0; i<=n; i++){
		cin >> v[i];
		sum += v[i];
		if(v[i] == 1) check1++;
	}
	
	if(check1 == n+1){
		cout << "perfect" << endl;
		return 0;
	}
	
	solve(1, 1);
	
	if(check(1)){
		cout << "perfect" << endl;
		return 0;
	}
	
	cout << "ambiguous" << endl;
	
	p[1] = 0;
	dfs(1);
	
	for(int i=0; i<sum; i++){
		if(i) cout << " ";
		cout << p[i+1];
	}
	cout << endl;
	
	rearrange(1);
	
	for(int i=0; i<sum; i++){
		if(i) cout << " ";
		cout << p[i+1];
	}
	cout << endl;
}
	
	
	
	
	
	