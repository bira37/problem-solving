#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;

//////////////////////////////////////////////STL - Ordered Set////////////////////////////////////////////
typedef tree<
int, //change for pair<int,int> to use like multiset
null_type,
less< int >, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int differ = 0;
//////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////

ordered_set s[100001];
bitset<100001> prime;
int lf[100001];

void sieve(){
	for(int i=1; i<=100000; i++){
		lf[i] = i;
	}
	prime.reset();
	int sqr = sqrt(100000);
	for(int i=2; i <= sqr; i++){
		if(!prime[i]){
			for(int j = i*i; j<=100000; j+=i){
				lf[j] = min(lf[j], i);
				prime.set(j);
			}
		}
	}
}

void factorize(int n, vector<int> & fac){
	while(n > 1){
		if(fac.size() == 0 || fac.back() != lf[n]) fac.push_back(lf[n]);
		n /= lf[n];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	sieve();
	int n;
	cin >> n;
	
	int v[n];
	vector<int> fac[n];
	
	for(int i=0; i<n; i++){
		cin >> v[i];
		factorize(v[i], fac[i]);
		int sz = fac[i].size();
		for(int mask = 1; mask < (1<<sz); mask++){
			int num = 1;
			for(int k=0; k<sz; k++) if(mask & (1<<k)) num*=fac[i][k];
			s[num].insert(i);
		}
	}
	
	int q;
	cin >> q;
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
		
			int idx, val;
			cin >> idx >> val;
			idx--;
			int sz = fac[idx].size();
			for(int mask = 1; mask < (1<<sz); mask++){
				int num = 1;
				for(int k=0; k<sz; k++) if(mask & (1<<k)) num*=fac[idx][k];
				s[num].erase(idx);
			}
			
			fac[idx].clear();
			v[idx] = val;
			factorize(v[idx], fac[idx]);
			
			sz = fac[idx].size();
			for(int mask = 1; mask < (1<<sz); mask++){
				int num = 1;
				for(int k=0; k<sz; k++) if(mask & (1<<k)) num*=fac[idx][k];
				s[num].insert(idx);
			}
			
		}
		else {
			int l,r,x;
			cin >> l >> r >> x;
			l--,r--;
			vector<int> f;
			factorize(x, f);
			int sz = f.size();
			int ans = 0;
			for(int mask = 1; mask < (1<<sz); mask++){
				int num = 1;
				for(int k=0; k<sz; k++) if(mask & (1<<k)) num*=f[k];
				int to_add = 0;
				to_add = s[num].order_of_key(r+1) - s[num].order_of_key(l);
				if(__builtin_popcount(mask) % 2 == 0) to_add = -1*to_add;
				ans += to_add;
			}
			cout << (r-l+1) - ans << endl;
		}
	}
}
