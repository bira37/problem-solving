#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, k;	
		cin >> n >> k;
		int v[n];
		int cont[10001];
		for(int i=0; i<=10000; i++) cont[i] = 0;
		priority_queue<int> pq;
		for(int i=0; i<n; i++){
			cin >> v[i];
			if(i < k){
				pq.push(v[i]);
				cont[v[i]]++;
			}
		}
		cout << pq.top();
		for(int i=k; i<n; i++){
			cont[v[i-k]]--;
			pq.push(v[i]);
			cont[v[i]]++;
			while(cont[pq.top()] < 1){
				pq.pop();
			}
			cout << " " << pq.top();
		}
		cout << endl;
	}
}
	
