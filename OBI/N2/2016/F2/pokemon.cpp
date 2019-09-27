#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define int long long
using namespace std;

int32_t main(){
	fastio;
	int x;
	cin>>x;
	int v[3];
	cin>>v[0]>>v[1]>>v[2];
	sort(v,v+3);
	int r=0;
	for(int i=0;i<3;i++){
		if(x>=v[i]){
			r++;
			x-=v[i];
		}
	}
	cout<<r<<endl;
}