#include <bits/stdc++.h>
 
using namespace std;
 
long long binomial(long long i, long long j){
 long long C[2][j+1];
 for(long long n = 0 ;n<=i;n++){
  for(long long m = 0;m<=min(j,n);m++){
   if(m ==0|| n == m){
    C[n&1][m] = 1;
   }
   else{
    C[n&1][m] = C[!(n&1)][m-1] + C[!(n&1)][m];
   }
  }
 }
 return C[i&1][j];
}
 
int main(){
	int n;
	cin >> n;
	int v[n];
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	sort(v, v+n);
	long long ans = 1;
	long long ptr= 3;
	while(ptr < n && v[ptr-1] == v[ptr]){
		ans++;
		ptr++;
	}
	if(v[0] == v[1] && v[1] == v[2]) cout << binomial(ans+2,3) << endl;
	else if(v[0] != v[1] && v[1] == v[2]) cout <<  binomial(ans+1, 2) << endl;
	else cout << ans << endl;
}
