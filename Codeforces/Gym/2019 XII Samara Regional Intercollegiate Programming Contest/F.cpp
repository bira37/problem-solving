#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define ff first
#define ss second
#define pb(x) push_back(x)
#define td(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector< tuple<int,int,int> > a(n), h(n);
	for(int i=0; i<n; i++){
		cin >> get<0>(a[i]) >> get<0>(h[i]);
		get<1>(h[i]) = get<0>(a[i]);
		get<2>(a[i]) = get<2>(h[i]) = i;
		get<1>(a[i]) = get<0>(h[i]);
	}
	set< ii, greater< ii > > s;
	sort(a.begin(), a.end());
	sort(h.begin(), h.end());
	reverse(h.begin(), h.end());
	int ans = 0;
	int l = 0;
	int r = 1;
	for(auto tatk : a){
		int atk, hp, id;
		tie(atk, hp, id) = tatk;
		while(h.size() > 0 && get<0>(h.back()) <= atk){
			s.insert(ii(get<1>(h.back()), get<2>(h.back())));
			h.pop_back();
		}
		bool ok = false;
		if(s.count(ii(atk, id))){
			s.erase(s.find(ii(atk, id)));
			ok = true;
		}
		if(s.size() == 0){
			if(ok) s.insert(ii(atk, id));
			continue;
		}
		int atk_ans = (*s.begin()).ff;
		if(ans < atk_ans + atk*(hp <= atk_ans)){
			ans = atk_ans + atk*(hp <= atk_ans);
			l = id;
			r = (*s.begin()).ss;
		}
		if(ok) s.insert(ii(atk, id));
	}
	cout << ans << endl << l+1 << " " << r+1 << endl;
		
 }
	
