#include <bits/stdc++.h>
#define endl '\n'
#define ii pair<int ,int> 
#define ff first
#define ss second
using namespace std;

int v[100000];
int a[100000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> v[i];
			a[i] = v[i];
		}
		
		queue< ii > q;
		//cout << "ue" << endl;
		for(int i=0; i<n; i++){
			if(!q.empty() && q.front().ss != a[i]){
				swap(a[i], a[q.front().ff]);
				q.pop();
			}
			else q.push(ii(i, a[i]));
		}
		
		for(int i=0; i<n; i++){
			if(q.empty()) break;
			if(q.front().ss != a[i]){
				swap(a[i], a[q.front().ff]);
				q.pop();
			}
		}
		int ans = 0;
		for(int i=0; i<n; i++){
			if(a[i] != v[i]) ans++;
		}
		cout << ans << endl;
		for(int i=0; i<n; i++){
			if(i) cout << " ";
			cout << a[i];
		}
		cout << endl;
	}
}
			
		
