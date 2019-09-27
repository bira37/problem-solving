#include <bits/stdc++.h>
#define int long long
#define dl long double
#define ff first
#define ss second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 5500
#define inf 1000000000
using namespace std;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
 
int32_t main(){
	fastio;
	int n;
	cin>>n;
	if(n==1)cout<<"1\n";
	else if(n<4)cout<<"NO SOLUTION\n";
	else if(n==4) cout<<"3 1 4 2 \n";
	else{
		for(int i=1;i<=n;i+=2)cout<<i<<" ";
		for(int i=2;i<=n;i+=2)cout<<i<<" ";
		cout<<endl;
		
	}
}