#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <utility>

using namespace std;

int N;
int val[100000];
int best[100000+1];
int sum[100000+1];

int main() {
	scanf(" %d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %d", &val[i]);
	}
	sum[0] = 0;
	best[0] = 0;
	for (int i = 0; i < N; i++) {
		sum[i+1] = sum[i] + val[i];
		best[i+1] = max(best[i], sum[i+1]);
		printf("%d\n",best[i+1]);
	}
	int ans = 0;
	for (int i = 0; i <= N; i++) {
		ans = max(ans, best[i] + (sum[N] - sum[i]));
	}
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		tmp = max(0, tmp + val[i]);
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}