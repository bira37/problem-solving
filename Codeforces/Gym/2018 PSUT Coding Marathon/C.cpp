#include <bits/stdc++.h>
using namespace std;
int ans = 0;
deque<int> dq;
int n;
 
int32_t main(){
	scanf("%d" , &n);
	for(int i = 0 ; i < n;i ++){
		int x;
		scanf("%d" , &x);
		while(dq.size() && dq.back() <= x) dq.pop_back() ;
		if(dq.empty()) ans++;
		dq.push_back(x);
	}
	printf("%d\n" , ans);
}
