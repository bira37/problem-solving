#include <bits/stdc++.h>

using namespace std;

map <long long, long long> best;

long long compute(long long n){
	if(n == 0) return 0;
	//cout << n << endl;
	long long c1,c2,c3;
	c1 = (best.count(n/2) ? best[n/2] : compute(n/2));
	c2 = (best.count(n/3) ? best[n/3] : compute(n/3));
	c3 = (best.count(n/4) ? best[n/4] : compute(n/4));
	long long ans = c1+c2+c3;
	if(n < ans){
		best[n] = ans;
		return ans;
	}
	else{
		best[n] = n;
		return n;
	}
}
	

int main(){
	long long n;
	while(cin >> n) cout << compute(n) << endl;
}

