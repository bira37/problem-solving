#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
struct par{
	int idx, num;
	par(){}
	par(int a, int b) : idx(a) , num(b) {}
};
 
int calculate(vector<int> & v){
	vector< par >  q;
	int ans = 0;
	q.push_back(par(-1,-1));
	for(int i=0; i<v.size(); i++){
			while(q.size()>1 && q.back().num < v[i]){
				par aux = q.back();
				q.pop_back();
				ans += aux.num*(i - aux.idx)*(aux.idx - q.back().idx);
			}
			q.push_back(par(i, v[i]));
	}
	while(q.size()>1){
		//cout << q.back().idx << " " << q.back().num << endl;
		par aux = q.back();
		q.pop_back();
		ans += aux.num*(v.size() - aux.idx)*(aux.idx - q.back().idx);
		//cout << "sum : " << ans << endl;
	}
	return ans;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> nv(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
		nv[i] = -v[i];
	}
	cout << calculate(v) + calculate(nv) << endl;
}
