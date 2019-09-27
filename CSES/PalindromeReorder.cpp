#include <bits/stdc++.h>
#define int long long
#define dl long double
#define ff first
#define ss second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 100100
#define inf 1000000000
using namespace std;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
 
int mod(int a,int m){
	int r = a%m;
	if(r<0)r+=m;
	return r;
}
 
int exp(int a,int n,int m){
	if(n==0)return 1;
	if(n==1)return a;
	int r = exp(a,n/2,m);
	r = mod(r*r,m);
	if(n&1)r=mod(r*a,m);
	return r;
}
 
int letras[30];
 
int32_t main(){
	fastio;
	string s;
	cin>>s;
	int n = s.size();
	memset(letras,0,sizeof(letras));
	for(int i=0;i<n;i++){
		letras[s[i]-'A']++;
	}
	int impar=0;
	for(int i=0;i<26;i++){
		if(letras[i]&1)impar++;
	}
	if(impar>1){
		cout<<"NO SOLUTION\n";
	}
	string r1="",r2="";
	char imp='?';
	for(int i=0;i<26;i++){
		int cnt = letras[i];
		if(cnt==0)continue;
		if(cnt%2==1){
			imp='A'+i;
			cnt--;
		}
		for(int j=0;j<cnt/2;j++){
			r1+=('A'+i);
			r2+=('A'+i);
		}
	}
	reverse(r2.begin(),r2.end());
	if(imp!='?')r1+=imp;
	r1+=r2;
	cout<<r1<<endl;
	
}