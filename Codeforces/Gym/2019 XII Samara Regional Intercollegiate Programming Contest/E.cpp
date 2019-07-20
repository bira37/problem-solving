#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define pb(x) push_back(x)
#define td(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
int lb(vector<pii> &v,int obj){
	int l = 0, r = v.size()-1,m;
	int ans = 0;
	while(l<=r){
		m = (l+r)/2;
		if(v[m].ff > obj){
			r = m-1;
		}
		else{
			l = m+1;
			ans = m;
		}
	}
	return ans;
}
bool cmp(pii a,pii b){
	return (a.ff == b.ff ? a.ss > b.ss : a.ff < b.ff);
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<pii> v(n);
	map<pii,int> pos;
	for(int i=0;i<n;i++){
		cin >> v[i].ff >> v[i].ss;
		pos[v[i]] = i+1;
	}
	sort(td(v),cmp);
	vector<pii> pf(n);
	for(int i=0;i<n;i++){
		if(i==0){
			pf[i] = pii(v[i].ss,pos[v[i]]);
		}
		else if(pf[i-1].ff < v[i].ss){
			pf[i] = pii(v[i].ss,pos[v[i]]);
		}
		else pf[i] = pf[i-1];
	}
	if(v[0].ff != 1){
		cout << "NO" << endl;
		return 0;
	}
	int r=v[0].ss;
	int last = 0;
	int p = lb(v,r+1);
	vector<int> ans;
	ans.pb(pos[v[0]]);
	while(r!=m){
		if(last == r){
			cout << "NO" << endl;
			return 0;
		}
		pii x = pf[p];
		last = r;
		r = x.ff;
		ans.pb(pf[p].ss);
		p = lb(v,r+1);
	}
	cout << "YES" << endl;
	cout << ans.size() << endl;
	for(int x : ans){
		cout << x << " ";
	}
	cout << endl;
}
