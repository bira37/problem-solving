#include <bits/stdc++.h>
#define ff first
#define ss second
#define pii pair<int,int>
 
using namespace std;
 
int main(){
	int n,k;
	cin >> n >> k;
	int count[20000];
	for(int i=0; i<20000; i++){
		count[i] = 0;
	}
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		count[x]++;
	}
	int ans = 0;
	for(int i=0; i<k; i++){
		if(count[i] == 0) ans++;
	}
	ans += count[k];
	cout << ans << endl;
}
