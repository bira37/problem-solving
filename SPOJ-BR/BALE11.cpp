#include <bits/stdc++.h>
#define pb push_back

using namespace std;

long long mergesort_count(vector<int> & v){
	vector<int> a,b;
	if(v.size() == 1) return 0;
	for(int i=0; i<v.size()/2; i++) a.push_back(v[i]);
	for(int i=v.size()/2; i<v.size(); i++) b.push_back(v[i]);
	long long ans = 0;
	ans += mergesort_count(a);
	ans += mergesort_count(b);
	a.push_back((int)(1e6));
	b.push_back((int)(1e6));
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

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	vector<int> v1 = v;
	cout << mergesort_count(v) << endl;
}
	

