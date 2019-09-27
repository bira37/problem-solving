#include <iostream>
#define MAXK 100100
using namespace std;

int dp[MAXK];
int A[110];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<=k;i++)dp[i]=-1;
	
	for(int i=0;i<n;i++)cin>>A[i];
	
	dp[0]=1;
	
	for(int i=0;i<n;i++){
		dp[A[i]]=0;
	}

	for(int i=1;i<=k;i++){
		if(dp[i]==-1){
			dp[i]=1;
			for(int j=0;j<n;j++){
				if(i+A[j]<=k){
				dp[i+A[j]]=0;
                }
                }
		}
	}
	if(dp[k]==1){
		cout<<"Second\n";
	}else cout<<"First\n";
	
}
