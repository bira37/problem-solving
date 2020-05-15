#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a,b,c;
	scanf("%llx %llx %llx", &a, &b, &c);
	long long x = (a/b)*(a/b);
	long long y = (b/c)*(b/c);
	long long res = x*y + x + 1;
	printf("%llx\n", res);
}
