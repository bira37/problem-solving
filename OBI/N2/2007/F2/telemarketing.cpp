#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAXN 10010
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
int vezes[MAXN];
int32_t main(){
	int n,l;
	cin>>n>>l;
	priority_queue<pii,vector<pii>,greater<pii> > fila;
	for(int i=1;i<=n;i++){
		fila.push(pii(0,i));
	}
	memset(vezes,0,sizeof(vezes));
	
	
	for(int i=0;i<l;i++){
		int t;
		cin>>t;
		pii aux = fila.top();
		fila.pop();
		fila.push(pii(aux.first+t,aux.second));
		vezes[aux.second]++;
	}
	for(int i=1;i<=n;i++){
		cout<<i<<" "<<vezes[i]<<endl;
	}
	
}