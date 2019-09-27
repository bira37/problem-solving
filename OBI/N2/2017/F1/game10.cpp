#include <bits/stdc++.h>
#define MAXN 70
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int D[MAXN];
int E[MAXN];
int main(){
	fastio;
	int N,A,D;
	cin>>N>>A>>D;
	int res=0;
	if(A>=D){
		res=A-D;
	}else{
		res=N-D+A;
	}
		
		cout<<res<<endl;
}