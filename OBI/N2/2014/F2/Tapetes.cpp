#include <iostream>
#define int long long
using namespace std;

int32_t main(){
	int l,n;
	cin>>l>>n;
	int r=n-1+(l-n+1)*(l-n+1);
	cout<<r<<endl;
}