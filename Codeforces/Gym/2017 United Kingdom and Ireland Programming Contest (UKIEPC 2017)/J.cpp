#include <bits/stdc++.h>
using namespace std;
 
 
 
int main(){
	int n ;
	cin>>n;
	double ans = 0.00;
	for(int i = 0 ; i < n ; i ++){
		int x;
		cin>>x;
		if(x == 0) ans += 2.000;
		if(x == 1) ans += 1.000;
		if(x == 2) ans += 0.500;
		if(x == 4) ans+= 1.00/4.000;
		if(x == 8) ans+= 1.00/8.000;
		if(x == 16) ans+= 1.000/16.000;
	}
	cout<<fixed<<setprecision(6)<<ans<<endl;
}
