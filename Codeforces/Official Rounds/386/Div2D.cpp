#include <bits/stdc++.h>
#define N 80
#define ff first
#define ss second
 
using namespace std;
 
 
int main(){
	int n,k,a,b;	
	cin >> n >> k >> a >> b;
	
	char ca = 'G';
	char cb = 'B';
 
	string ans;	
	int cnt = 0;
	while(a+b > 0){
		if(a < b || cnt >= k){
			swap(a,b);
			swap(ca,cb);
			cnt = 0;
		}
		if(a == 0){
			cout << "NO" << endl;
			return 0;
		}
		ans+=ca;
		cnt++;
		a--;
	} 
	cout << ans << endl;	
}
