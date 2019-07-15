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

int vis[1123456];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	list< pair<char, int> > l;
	
	vector< list< pair<char, int> >::iterator > now;
	
	int n;
	string s;
	cin >> s;
	n = s.size();
	for(int i=0; i<n; i++) vis[i] = -1;
	for(int i =0; i<n; i++){
		char c = s[i];
		l.push_back(pair<char, int>(c, i));
	}
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	int i =0;
	//cout << "beggining" << endl;
	for(list< pair<char, int> >::iterator it = l.begin(); it != l.end(); ++it, ++i){
		if(i == 0){
			list< pair<char, int> >::iterator next = it; next++;
			if(it->first != next->first){
				now.pb(it);
				vis[it->second] = 0;
			}
			continue;
		}
		if(i == n-1){
			list< pair<char, int> >::iterator prev = it; prev--;
			if(it->first != prev->first){
				now.pb(it);
				vis[it->second] = 0;
			}
			continue;
		}
		list< pair<char, int> >::iterator next = it; next++;
		list< pair<char, int> >::iterator prev = it; prev--;
		if(it->first != prev->first || it->first != next->first){
			//cout << "inserting now " <<  it->first << endl;
			now.pb(it);
			vis[it->second] = 0;
		}
	}
	int ans = 0;
	while(!now.empty()){
		ans++;
		//cout << "at iteration " << ans << endl;
		vector< list< pair<char, int> >::iterator > analisa;
		for(auto it : now){
			if(it != l.begin()){
				list< pair<char, int> >::iterator prev = it; prev--;
				if(vis[prev->second] != ans && vis[prev->second] != ans-1){
					analisa.pb(prev);
					vis[prev->second] = ans;
				}
			}
			list< pair<char, int> >::iterator next = it; next++;
			if(next != l.end()){
				if(vis[next->second] != ans && vis[next->second] != ans-1){
					analisa.pb(next);
					vis[next->second] = ans;
				}
			}
		}
		for(auto it : now){
			l.erase(it);
		}
		now.clear();
		for(auto it: analisa){
			list< pair<char, int> >::iterator prev = it;
			list< pair<char, int> >::iterator next = it;
			next++;
			if(next == l.end()) next--;
			if(it != l.begin()) prev--;
			if(it->first != prev->first || it->first != next->first){
				//cout << "inserting now " <<  it->first << endl;
				now.pb(it);
			}
			else vis[it->second] = -1;
		}
	}
	
	cout << ans << endl;
}