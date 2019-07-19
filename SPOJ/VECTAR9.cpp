#include <bits/stdc++.h>
using namespace std;

long long mult[1<<13];
int number[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};

long long int numberMangu(long long int n){
	long long count=0;
	for(int mask=1; mask < (1 << 13); ++mask){
		if(__builtin_popcount(mask) % 2){
			count += n/mult[mask];
		}
		else count -= n/mult[mask];
	}
	return count;
}

int main(){
	for(int mask = 1; mask < (1<<13); ++mask){
		mult[mask] = 1;
		for(int i=0; i<13; ++i){
			if(mask & (1<<i)){
				mult[mask] = mult[mask] * number[i];
			}
		}
	}

	int t;
	long long n;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		long long ini = 1, fim = 304250263527210,ans = -1;
		while(ini <= fim){
			long long meio = (ini+fim)/2;
			long long k = numberMangu(meio);
			if(k>=n){
				ans = meio;
				fim = meio - 1;
			}
			else ini = meio + 1;
		}
		printf("%lld\n", ans);
	}
}


