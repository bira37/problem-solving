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
 
string s,t;
int dp[MAXN][MAXN];
 
int edit(int pos1,int pos2){
	if(pos1==-1)return pos2+1;
	if(pos2==-1)return pos1+1;
	if(dp[pos1][pos2]!=-1)return dp[pos1][pos2];
	if(s[pos1]==t[pos2]){
		return dp[pos1][pos2] = edit(pos1-1,pos2-1);
	}
	int op1 = edit(pos1-1,pos2)+1;
	int op2 = edit(pos1,pos2-1)+1;
	int op3 = edit(pos1-1,pos2-1)+1;
	return dp[pos1][pos2]=min(op1,min(op2,op3));
}
 
int32_t main(){
	fastio;
	cin>>s>>t;
	memset(dp,-1,sizeof(dp));
	cout<<edit(s.size()-1,t.size()-1)<<endl;
	
}