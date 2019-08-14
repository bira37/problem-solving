#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	int n, k;
	while(cin >> n >> k, n+k != 0){	
		int v[n];
		priority_queue<int> pq;
		map<int,int> m;
		for(int i=0; i<n; i++){
			cin >> v[i];
			if(i < k) pq.push(-v[i]);
		}
		cout << -pq.top();
		for(int i=k; i<n; i++){
			m[v[i-k]]++;
			pq.push(-v[i]);
			while(m[-pq.top()]){
				m[-pq.top()]--;
				pq.pop();
			}
			cout << " " << -pq.top();
		}
		cout << endl;
	}
}
	
