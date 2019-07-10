#include <bits/stdc++.h>
 
using namespace std;
 
struct prod{
	int disc, orig;
};
 
bool cmp(const prod & a, const prod & b){
	return (a.orig - a.disc) > (b.orig - b.disc);
}
 
int main(){
	
	int n,k;
	cin >> n >> k;
	prod v[n];
 
	for(int i=0; i <n; i++){
		cin >> v[i].disc;
	}
 
	for(int i=0; i <n; i++){
		cin >> v[i].orig;
	}
 
	sort(v, v+n, cmp);
 
	int ans = 0;
	int count = 0;
	int i = 0;
	while(v[i].orig - v[i].disc > 0 || count < k){
		ans += v[i].disc;
		count++;
		i++;
	} 
	
	for(int i=count; i<n; i++){
		ans += v[i].orig;
	}
 
	cout << ans << endl;
}
