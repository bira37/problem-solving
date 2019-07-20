#include <bits/stdc++.h>
 
using namespace std;
 
int n, k;
 
int v[212345];
 
bool check(int conv){
	int acc = 0;
	int have = conv;
	for(int i=0; i<n; i++){
		if(v[i] <= acc) acc++;
		else if(v[i] > acc && have > 0){
			acc++;
			have--;
		}
	}
	return acc >= k;
}
 
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	
	for(int i=0; i<n; i++) cin >> v[i];
	
	int l = 0, r = n;
	int ans = n;
	while(l <= r){
		int m = (l+r)/2;
		
		if(check(m)){
			ans = m;
			r = m-1;
		}
		else l = m+1;
	}
	
	cout << ans << endl;
}
