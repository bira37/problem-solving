#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	map<string, int> A,B;
	string a[n], b[n];
	bool vis[n];
	for(int i=0; i<n; i++){
		string x,y;
		cin >> x >> y;
		a[i] = x.substr(0,3);
		b[i] = x.substr(0,2) + y.substr(0,1);
		A[a[i]]++;
		vis[i] = false;
	}
	string res[n];
	for(int i=0; i<n; i++){
		if(A[a[i]] <= 1) res[i] = a[i];
		else {
			res[i] = b[i];
		}
	}
	queue<int> q;
	for(int i=0; i<n; i++){
		if((A.count(b[i]) && a[i] != b[i]) || (a[i] == b[i] && A[b[i]] > 1)) q.push(i);
	}
	while(!q.empty()){
		int atual = q.front();
		q.pop();
		if(vis[atual]) continue;
		vis[atual] = true;
		for(int i=0; i<n; i++){
			if(atual != i){
				if(b[atual] == res[i]){
					if(res[i] == a[i]){
						res[i] = b[i];
						q.push(i);
					}
					else {
						cout << "NO" << endl;
						return 0;
					}
				}
			}
		}
	}
	for(int i=0; i<n; i++) B[res[i]]++;
	if(B.size() != n){ 
		cout << "NO" << endl;
		return 0;
	}			
	cout << "YES" << endl;
	for(int i=0; i<n; i++){
		cout << res[i] << endl;
	}
}
