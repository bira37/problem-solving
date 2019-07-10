#include <bits/stdc++.h>
 
using namespace std;
 
struct tempo{
	long long l,r;
};
 
bool par1(const tempo & a, const tempo & b){
	return a.l < b.l;
}
 
bool par2(const tempo & a, const tempo & b){
	return a.r < b.r;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	
	cin >> n;
	tempo c[n];
	for(int i=0; i<n; i++){
		cin >> c[i].l >> c[i].r;
	}
 
	cin >> m;
	tempo p[m];
	for(int i=0; i<m; i++){
		cin >> p[i].l >> p[i].r;
	}
 
	sort(c, c+n, par1);
	sort(p, p+m, par2); 
 
	long long ans = 0;
	ans = max(ans , c[n-1].l - p[0].r);
 
	sort(c, c+n, par2);
	sort(p, p+m, par1);
	
	ans = max(ans , p[m-1].l - c[0].r);
 
	cout << ans << endl;
}
