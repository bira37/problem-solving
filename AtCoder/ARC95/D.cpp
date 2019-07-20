#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	scanf("%d", &n);
	ll v[n];
	ll max_n = 0;
	for(int i=0; i<n; i++){
		cin >> v[i];
		max_n = max(max_n, v[i]);
	}
	
	ll a, b;
	double best = 1123456789.0;
	
	for(int i=0; i<n; i++){
		if(v[i] == max_n) continue;
		
		if(best > abs((double)max_n/2. - (double)v[i])){
			a = max_n;
			b = v[i];
			best = abs((double)max_n/2. - (double)v[i]);
		}
	}
	
	printf("%lld %lld\n", a, b);
}
