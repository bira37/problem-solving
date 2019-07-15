#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define mod(n) (n%1000000007)
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second

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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,k;
	cin >> n >> k;
	stack<int> s;
	int a[n];
	bool vis[n+1];
	for(int i=1; i<=n; i++) vis[i] = false;
	int want = 1;
	for(int i=0; i<k; i++){
		cin >> a[i];
	}
	//phase 1
	for(int i=0; i<k; i++){
		while(!s.empty() && want == s.top()){
			s.pop();
			want++;
		}
		s.push(a[i]);
		vis[a[i]] = true;
	}
	while(!s.empty() && want == s.top()){
		s.pop();
		want++;
	}
	if(vis[want]){
		cout << -1 << endl;
		return 0;
	}
	if(s.empty()){
		int dec = 0;
		for(int i=k; i<n; i++){
			if(vis[n-dec]){
				cout << -1 << endl;
				return 0;
			}
			a[i] = n-dec;
			dec++;
		}
	}
	else {
		int i = k;
		while(!s.empty()){
			while(want != s.top()){
				if(vis[s.top()-1]){
					cout << -1 << endl;
					return 0;
				}
				s.push(s.top()-1);
				vis[s.top()] = true;
				a[i] = s.top();
				i++;
			}
			while(!s.empty() && want == s.top()){
				s.pop();
				want++;
			}
		}
		int dec = 0;
		for(;i<n; i++){
			if(vis[n-dec]){
				cout << -1 << endl;
				return 0;
			}
			a[i] = n-dec;
			dec++;
		}
	}
	for(int i=0; i<n; i++){
		if(i)  cout << " ";
		cout << a[i];
	}
	cout << endl;
}