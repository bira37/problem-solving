#include <bits/stdc++.h>
#define MOD 1000000007
 
using namespace std;
 
 
int main(){
	long long cnt = 0, ans = 0;
	string str;
	cin >> str;
	for(int i= str.size()-1; i>=0; i--){
		if(str[i] == 'b') cnt= (cnt+1)%MOD;
		else {
			ans = (ans + cnt)%MOD;
			cnt = (cnt*2)%MOD;
		}
	}
	cout << ans << endl;
}
