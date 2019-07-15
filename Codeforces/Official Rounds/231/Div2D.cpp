#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int v[112345];
int low, a;

bool check(int k){
	for(int j = 0; j < n; j++){
		int l = INT_MIN;
		int r = INT_MAX;
		int b = v[j] + k;
		for(int i=0; i<n; i++){
		  if(i == j) continue;
			if(i > j){
			  int inf = ((v[i] - k - b) + ((i- j) -1))/(i - j);
			  int sup = (v[i] + k - b)/(i - j);
			  l = max(l, inf);
			  r = min(r, sup);
			}
			else {
			  int inf = ((v[i] - k - b))/(i - j);
			  int sup = ((v[i] + k - b) +  ((i- j) +1))/(i - j);
			  swap(inf, sup);
			  l = max(l, inf);
			  r = min(r, sup);
			}
		}
		if(l <= r){
		  a = l;
		  low = (-j)*a + (v[j]+k);
		  return true;
		}
		l = INT_MIN;
		r = INT_MAX;
		b = v[j]-k;
		for(int i=0; i<n; i++){
		  if(i == j) continue;
		  if(i > j){
			  int inf = ((v[i] - k - b) + ((i- j) -1))/(i - j);
			  int sup = (v[i] + k - b)/(i - j);
			  l = max(l, inf);
			  r = min(r, sup);
			}
			else {
			  int inf = ((v[i] - k - b))/(i - j);
			  int sup = ((v[i] + k - b) +  ((i- j) +1))/(i - j);
			  swap(inf, sup);
			  l = max(l, inf);
			  r = min(r, sup);
			}
		}
		if(l <= r){
		  a = l;
		  low = (-j)*a + (v[j]-k);
		  return true;
		}
	}
	return false;
}

int32_t main(){
	scanf("%lld", &n);
	for(int i=0; i<n; i++){
		scanf("%lld", &v[i]);
	}
	sort(v, v+n);
	int l = 0, r = 10000;
	int ans = -1;
	while(l <= r){
		int m = (l+r)/2;
		if(check(m)){
			ans = m;
			r = m-1;
		}
		else l = m+1;
	}
	
	printf("%lld\n%lld %lld\n", ans, low, a);
}