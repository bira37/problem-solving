#include<bits/stdc++.h>
#define pb push_back	
#define int long long
#define endl '\n'
using namespace std;
 
signed main(){
	int n;
	cin >> n;
	vector<int> v;
	for(int i=0; i<=n; i++) v.pb(i);
	
	int b = 0;
	vector<int> id;
	for(int i=1; i<=n; i++) id.pb(i);
	while(v.size() > 1){
		int cnt0 = 0, cnt1 = 0;
		for(int x : v){
			if((1LL<<b) & x) cnt1++;
			else cnt0++;
		}
		int qry0 = 0, qry1 = 0;
		vector<int> bits;
		for(int idx : id){
			cout << "? " << idx << " " << b << endl;
			cout.flush();
			int bit;
			cin >> bit;
			if(bit) qry1++;
			else qry0++;
			bits.pb(bit);
		}
		vector<int> new_v;
		vector<int> new_id;
		if(cnt0 != qry0){
			for(int x : v){
				if((1LL<<b) & x){}
				else new_v.pb(x);
			}
			for(int i=0; i<id.size(); i++) if(bits[i] == 0) new_id.pb(id[i]);
		}
		else {
			for(int x : v){
				if((1LL<<b) & x) new_v.pb(x);
			}
			for(int i=0; i<id.size(); i++) if(bits[i] == 1) new_id.pb(id[i]);
		}
		v.swap(new_v);
		id.swap(new_id);
		b++;
	}
	cout << "! " << v[0] << endl;	
} 	
