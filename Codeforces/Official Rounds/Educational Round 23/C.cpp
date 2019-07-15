#include <bits/stdc++.h>
#define int long long
using namespace std;
	
bool check(int n, int s){
	int digit = 0;
	int num = n;
	while(n> 0){
		digit += n%10;
		n/=10;
	}
	return (num - digit >= s);
}
int32_t main(){
	int n,s;
	cin >> n >> s;
	int l = 0, r = n;
	int ans = n+1;
	while(l <=r ){
		int m = (l+r)>>1;
		if(check(m,s)){
			ans = m;
			r = m-1;
		}
		else l = m+1;
	}
	cout << n-ans + 1 << endl;
}