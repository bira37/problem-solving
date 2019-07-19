#include <bits/stdc++.h>

using namespace std;

long long sum = 0;
void merge_inversion_count(vector<long long> & v){
	vector<long long> a,b;
	if(v.size()==1) return;
	for(int i=0; i<v.size()/2; i++) a.push_back(v[i]);
	for(int i=v.size()/2; i<v.size(); i++) b.push_back(v[i]);
	
	merge_inversion_count(a);
	merge_inversion_count(b);

	a.push_back(INT_MAX);
	b.push_back(INT_MAX);
	long long x = 0, y = 0;
	//cout << "comparing " << endl;
	//for(int i=0; i<a.size()-1; i++) cout << a[i] << " ";
	//cout << endl;
	//for(int i=0; i<b.size()-1; i++) cout << b[i] << " ";
	//cout << endl;
	for(int i=0; i<v.size(); i++){
		if(a[x] < b[y]){
			//cout << "inversion times " << b.size()-y-1 << endl;
			sum += a[x]*(long long)(b.size()-y-1);
			v[i] = a[x++];
		}
		else {
			v[i] = b[y++];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> v(n);
		for(int i=0; i<n; i++){
			cin >> v[i];
		}
		sum = 0;
		merge_inversion_count(v);
		cout << sum << endl;
	}
}
		
