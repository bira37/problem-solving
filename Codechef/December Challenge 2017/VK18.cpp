#include <bits/stdc++.h>

using namespace std;

long long v[2000001];
long long ans[2000001];

int process(int n){
	int odd = 0;
	int even = 0;
	while(n > 0){
		int val = n%10;
		if(val%2) odd += val;
		else even += val;
		n/=10;
	}
	return abs(even-odd);
}

int main(){
	int t;
	scanf("%d", &t);
		
	for(int i=0; i<=2000000; i++){
		if(i) v[i] = v[i-1]+process(i);
		else v[i] = process(i);
	}

	ans[1] = 2;
	
	for(int i=2; i<=1000000; i++){
		ans[i] = ans[i-1] + 2*(v[2*i-1] - v[i]) + (v[2*i] - v[2*i-1]);
	}
	
	
	
	while(t--){
		int n;
		scanf("%d", &n);
		printf("%lld\n", ans[n]); 
	}
}
