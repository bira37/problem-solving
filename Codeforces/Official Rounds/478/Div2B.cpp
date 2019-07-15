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

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int v[14];
	int best = 0;
	for(int i=0; i<14; i++){
	  cin >> v[i];
	}
	int a[14];
	for(int i=0; i<14; i++) a[i] = v[i];
	for(int i=0; i<14; i++){
	  //trying move i
	  if(v[i] == 0) continue;
	  int curr = v[i];
	  v[i] = 0;
	  for(int j=i+1; j<14; j++){
	    v[j]++;
	    curr--;
	    if(curr == 0) break;
	  }
	  int distribui = curr/14;
	  for(int j=0; j<14; j++) v[j] += distribui;
	  int resta = curr%14;
	  for(int j=0; j<resta; j++) v[j]++;
	  int pont = 0;
	  for(int j=0; j<14; j++) if(v[j]%2 == 0) pont+= v[j];
	  best = max(pont, best);
	  for(int j=0; j<14; j++) v[j] = a[j];
	}
	cout << best << endl;
}