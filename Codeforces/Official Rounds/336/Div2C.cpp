#include <bits/stdc++.h>
#define ii pair<int, int>
#define a first
#define b second
using namespace std;

int dp[112345];
int ans = 0;

ii beacon[112345];
	
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> beacon[i].a >> beacon[i].b;
	}
	
	sort(beacon, beacon+n);
	
	for(int i=0; i<n; i++) dp[i] = 0;
	
	int curr = 0;
	for(int i=0; i<n; i++){
	  int l = 0, r = i -1;
  	int ans = i;
  	while(l <= r){
  	  int m = (l+r)>>1;
  	  if(beacon[m].a >= beacon[i].a - beacon[i].b){
  	    ans = m;
  	    r = m-1;
  	  }
  	  else l = m+1;
  	}
  	dp[i] = (ans-1 >= 0 ? dp[ans-1] : 0) + 1;
  	curr = max(dp[i], curr);
	}
	cout << n - curr << endl;
}