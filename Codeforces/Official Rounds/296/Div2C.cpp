#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int h,w,n;
	cin >> w >> h >> n;
	
	set<int> H,V;
	
	multiset< int, greater<int> > DH, DV;
	
	H.insert(0);
	H.insert(h);
	V.insert(0);
	V.insert(w);
	
	DH.insert(h);
	DV.insert(w);
	
	while(n--){
		char q;
		int x;
		cin >> q >> x;
		if(q == 'H'){
			H.insert(x);
			auto it = H.find(x);
			it--;
			int l = *it;
			it++;
			it++;
			int r = *it;
			DH.erase(DH.find(r-l));
			DH.insert(x-l);
			DH.insert(r-x);
		}
		else {
			V.insert(x);
			auto it = V.find(x);
			it--;
			int l = *it;
			it++;
			it++;
			int r = *it;
			DV.erase(DV.find(r-l));
			DV.insert(x-l);
			DV.insert(r-x);
		}
		cout << (*DV.begin()) * (*DH.begin()) << endl;
	}
}