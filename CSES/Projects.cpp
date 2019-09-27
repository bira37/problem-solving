#include <bits/stdc++.h>
#define ff first
#define ss second
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> pii;
struct dados{
	   int x,y,val;	
};
 
int cmp(dados a,dados b){
	return a.x<b.x;
}
 
vector<dados> v;
 
int32_t main(){
	fastio;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y,val;
		cin>>x>>y>>val;
		dados aux = {x,y,val};
		v.push_back(aux);
		
	}
	sort(v.begin(),v.end(),cmp);
	set<pii> final;
	int maior = 0;
	int res=0;
	
	for(int i=0;i<n;i++){
		int x,y,val;
		x = v[i].x;
		y = v[i].y;
		val = v[i].val;
		
		while(final.size()>0 && final.begin()->ff < x){
			maior = max(maior,final.begin()->ss);
			final.erase(final.begin());
		}
		int atual = maior+val;
		res=max(res,atual);
		final.insert(pii(y,atual));
	}
	
	cout<<res<<endl;
}