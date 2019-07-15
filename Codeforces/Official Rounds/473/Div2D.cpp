#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define endl '\n'
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;

inline int mod(int n){ return (n%1000000007); } 

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

bool prime[2000001];
int sp[2000001];

void process(){
	for(int i=0; i<=2000000; i++){
		prime[i] = true;
		sp[i] = i;
	}
	prime[0] = false;
	prime[1] = false;
	for(int i=2; i<=sqrt(2000000); i++){
		if(!prime[i]) continue;
		for(int j = i; j<=2000000; j+=i){
			prime[j] = false;
			sp[j] = min(sp[j], i);
		}
	}
}

void factorize(int n, vector<int> & fac){
	while(n > 1){
		fac.push_back(sp[n]);
		n /= sp[n];
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	set<int> s;
	process();
	for(int i=2; i<=2000000; i++){
		s.insert(i);
	}
	int n;
	cin >> n;
	int b[n];
	bool greater = false;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		if(!greater) b[i] = *s.lower_bound(a);
		else b[i] = *s.lower_bound(1);
		if(a < b[i]) greater = true;
		vector<int> fac;
		factorize(b[i], fac);
		for(int lf : fac){
			for(int k = lf; k <= 2000000; k+= lf) s.erase(k);
		}
		if(i) cout << " ";
		cout << b[i];
	}
	cout << endl;
}