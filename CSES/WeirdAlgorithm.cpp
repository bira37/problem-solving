#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>  pii;
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin>>n;
	while(n!=1){
		cout<<n<<endl;
		if(n%2==0) n/=2;
		else n=3*n+1;
	}
	cout<<1<<endl;
}