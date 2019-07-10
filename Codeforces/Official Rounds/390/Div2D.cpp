#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	long long n,k;
	cin >> n >> k;
	multiset<int> s;
	pair<long long, long long> cup[n],original[n];
	for(int i=0; i<n; i++){
		cin >> cup[i].first >> cup[i].second;
		original[i].first = cup[i].first;
		original[i].second = cup[i].second;
	}
 
	sort(cup, cup+n);
	long long l,r;
	for(int i=0; i<k; i++){
		s.insert(cup[i].second);
	}
	l = cup[k-1].first;
	r = *s.begin(); 
	for(int i=k; i<n; i++){
		s.erase(s.begin());
		s.insert(cup[i].second);
		int li = cup[i].first;
		int ri = *s.begin();
		if(ri - li > r - l){
			l = li;
			r = ri;
		}
	}
	if(r < l){
		cout << 0 << endl;
		for(int i=0; i<k; i++){
			if(i==0) cout << i+1;
			else cout << " " << i+1;
		}
	}
	else{
		cout << r - l + 1 << endl;
		for(int i=0, it = 0; i<n && it < k; i++){
			if(original[i].first <= l && original[i].second >= r){
				if(it == 0) cout << i+1;
				else cout << " " << i+1;
				it++;
			}
		}
	}
	cout << endl;
}
