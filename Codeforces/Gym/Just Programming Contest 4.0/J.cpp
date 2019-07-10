#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		long long acc = 1;
		for(int i=0; i<n; i++){
			long long k;
			scanf("%I64d", &k);
			acc *= (k+1);
			acc %= M;
		}
		printf("%I64d\n", acc-1);
	}
}
