#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define mod(n) (n%1000000007)
#define pb push_back
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define int long long

using namespace std;
using namespace __gnu_pbds;

//////////////////////////////////////////////STL - Ordered Set////////////////////////////////////////////
typedef tree<
int, //change for pair<int,int> to use like multiset
null_type,
less<int>, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int differ = 0;
//////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////

struct ii{
	int l, r;
	ii(int a, int b) : l(a), r(b) {}
	bool operator<(const ii & b) const {
   		return r < b.r;
  	}
};

bool contains(ii a, ii b){
	return (b.l <= a.l && a.r <= b.r);
}

set< ii > s;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int ans = n;
	
	int q;
	cin >> q;
	while(q--){
		int a, b, k;
		cin >> a >> b >> k;
		if(k == 1){
			vector< ii > to_up;
			set< ii >::iterator lb = s.lower_bound(ii(a,a));
			while(lb != s.end() && lb->r <= b){
				to_up.pb(*lb);
				lb++;
			}
			//if(q == 2){cout << a << " " << b << endl; for(ii x : to_up) cout << x.l << " " << x.r << endl;}
			if(to_up.size() == 0){
				if(lb == s.end()){
					ans -= (b-a+1);
					s.insert(ii(a,b));
				}
				else if(lb != s.end() && b < lb->l){
					ans -= (b-a+1);
					s.insert(ii(a,b));
				}
				else if(a < lb->l && lb->l <= b && b <= lb->r){
					ans -= ((lb->l-1) - a + 1);
					s.insert(ii(a, lb->l-1));
				}
			}
			else{
				if(a < to_up[0].l){
					int la,ra;
					la = a;
					ra = to_up[0].l-1;
					if(la <= ra){
						s.insert(ii(la, ra));
						ans -= (ra-la+1);
					}
				}
				for(int i=1; i< to_up.size(); i++){
					int la, ra;
					la = to_up[i-1].r+1;
					ra = to_up[i].l-1;
					if(la <= ra){
						s.insert(ii(la, ra));
						ans -= (ra-la+1);
					}
				}
				int la, ra;
				la = to_up.back().r+1;
				if(lb != s.end()) ra = min(b, lb->l-1);
				else ra = b;
				if(la <= ra){
					s.insert(ii(la, ra));
					ans -= (ra-la+1);
				}
			}	 		
		}
		else {
			while(true){
				if(s.lower_bound(ii(a,a)) == s.end()) break;
				ii lb = *s.lower_bound(ii(a,a));
				if(lb.l <= a && b <= lb.r){
					s.erase(s.find(lb));
					ans += (b - a + 1);
					if(lb.l <= a-1) s.insert(ii(lb.l, a-1));
					if(b+1 <= lb.r) s.insert(ii(b+1, lb.r));
				}
				else if(lb.l <= a && a <= lb.r){
					s.erase(s.find(lb));
					ans += (lb.r - a + 1);
					if(lb.l <= a-1) s.insert(ii(lb.l, a-1));
				}
				else if(lb.l > b) break;
				else if(lb.l <= b && lb.r > b){
					s.erase(s.find(lb));
					ans += (b - lb.l + 1);
					if(b+1 <= lb.r) s.insert(ii(b+1, lb.r));
					break;
				}
				else {
					s.erase(s.find(lb));
					ans += (lb.r - lb.l + 1);
				}
			}
		}
		//for(ii x : s) cout << x.l << " " << x.r << endl;
		cout << ans << endl;
	}
}