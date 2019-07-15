#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
using namespace std;

long long mergesort_count(vector<int> & v){
	vector<int> a,b;
	if(v.size() == 1) return 0;
	for(int i=0; i<v.size()/2; i++) a.push_back(v[i]);
	for(int i=v.size()/2; i<v.size(); i++) b.push_back(v[i]);
	long long ans = 0;
	ans += mergesort_count(a);
	ans += mergesort_count(b);
	a.push_back(LLONG_MAX);
	b.push_back(LLONG_MAX);
	int x = 0, y = 0;
	for(int i=0; i<v.size(); i++){
		if(a[x] <= b[y]){
			v[i] = a[x++];
		}
		else {
			v[i] = b[y++];
			ans += a.size() - x -1;
		}
	}
	return ans;
}

int32_t main(){
  map<int,int> pos;
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int a,b;
    cin >> a >> b;
    if(!pos.count(a)) pos[a] = a;
    if(!pos.count(b)) pos[b] = b;
    swap(pos[a], pos[b]);
  }
  
  vector<int> used;
  vector<int> v;
  for(auto cur : pos){
    used.push_back(cur.ss);
    v.push_back(cur.ss);
  }
  sort(used.begin(), used.end());
  int ans = mergesort_count(v);
  for(auto cur : pos){
    int l = cur.ff;
    int r = cur.ss;
    if(l > r) continue;
    int lb = lower_bound(used.begin(), used.end(), l) - used.begin();
    int ub = upper_bound(used.begin(), used.end(), r) - used.begin() - 1;
    ans += (r-l+1) - (ub - lb+1);
  }
  for(auto cur : pos){
    int l = cur.ss;
    int r = cur.ff;
    if(l > r) continue;
    int lb = lower_bound(used.begin(), used.end(), l) - used.begin();
    int ub = upper_bound(used.begin(), used.end(), r) - used.begin() - 1;
    ans += (r-l+1) - (ub - lb+1);
  }
  cout << ans << endl;
}