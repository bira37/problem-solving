#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define M 1000000007
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second
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

bool lucky(int n){
	bool ans = true;
	while(n > 0){
		if(n%10 != 7 && n%10 != 4) ans = false;
		n/=10;
	}
	return ans;
}

int fat[112345];
int inv[112345];

int expo(int a, int k){
	if(k == 1) return a;
	if(k == 0) return 1;
	int aux = expo(a, k/2);
	aux %= M;
	aux *= aux;
	aux %= M;
	if(k%2) aux *= a;
	aux %= M;
	return aux;
}

void calc(){
	fat[0] = 1;
	inv[0] = 1;
	fat[1] = 1;
	inv[1] = 1;
	for(int i=2; i<112345; i++){
		fat[i] = i*fat[i-1];
		fat[i] %= M;
		inv[i] = expo(fat[i], M-2);
		inv[i] %= M;
	}
}

int C(int n, int k){
	//cout << fat[n] << " " << inv[n-k] << " " << inv[k] << endl;
	return (((fat[n]*inv[n-k])%M)*inv[k])%M;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,k;
	cin >> n >> k;
	calc();
	int v[n];
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	sort(v, v+n);
	vector<int> luc;
	map<int, int> cnt;
	int nonlucky = 0;
	for(int i=0; i<n; i++){
		if(lucky(v[i])){
			//cout << v[i] << " is lucky" << endl;
			cnt[v[i]]++;
			if(luc.size() == 0) luc.push_back(v[i]);
			else if(luc.back() != v[i]) luc.push_back(v[i]);
			continue;
		}
		else nonlucky++;
	}
	int sum[luc.size()];
	for(int i=0; i<luc.size(); i++) sum[i] = cnt[luc[i]];
	int dp[luc.size()+1][luc.size()+1];
	for(int i=0; i<=luc.size(); i++){
		for(int j=0; j<=luc.size(); j++){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for(int i=0; i<luc.size(); i++){
		for(int j=0; j<=luc.size(); j++){
			if(dp[i][j] == 0) continue;
			dp[i+1][j] += dp[i][j];
			dp[i+1][j] %= M;
			dp[i+1][j+1] += dp[i][j]*sum[i];
			dp[i+1][j+1] %= M;
		}
	}
	
	int ans = 0;
	//cout << "non luck " << nonlucky << endl;
	for(int i=0; i<=min(k, (int)luc.size()); i++){
		//cout << "i = " << i << endl;
		if(k-i > nonlucky) continue;
		int tmp = dp[luc.size()][i]*C(nonlucky, k-i);
		//cout << dp[luc.size()][i] << " " << C(nonlucky, k-i) << endl;
		tmp %= M;
		ans += tmp;
		ans %= M;
	}
	cout << ans << endl;
}