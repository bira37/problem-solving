#include <bits/stdc++.h>
using namespace std;
int n ;
 
int a[100006];
vector<int> adj[100005];
deque<int> dsu[100005];
 
 
void solve(int i , int j){
	for(auto p : adj[i]){
		if(p == j) continue;
		int x = dsu[i].size();
		solve(p , i);
		if(x > dsu[p].size()){
			while(dsu[p].size()){
				dsu[i].push_back(dsu[p].front() + x);
				dsu[p].pop_front();
			}	
		}
		else{
			swap(dsu[p] , dsu[i]) ;
			x = dsu[i].size();
			while(dsu[p].size()){
				dsu[i].push_back(dsu[p].front() + x);
				dsu[p].pop_front();
			}
		}
	}
	dsu[i].push_front(dsu[i].size() + 1) ;
}
 
 
int32_t main(){
	scanf("%d" ,&n);
	for(int i = 1 ; i <= n; i ++){
		scanf("%d" , &a[i]);
		if(a[i] == 0) continue;
		else adj[a[i]].push_back(i) , adj[i].push_back(a[i]);
	}
	vector<int> ans;
	for(int i = 1 ; i <= n; i ++){
		if(a[i] == 0){
			solve(i, i);
			int k = ans.size();
			while(dsu[i].size()){
				ans.push_back(dsu[i].front() + k);
				dsu[i].pop_front() ; 
			}
		}	
	}
	for(int i = 0 ; i < ans.size() ; i++){
		printf("%d " , ans[i]);
	}
}
