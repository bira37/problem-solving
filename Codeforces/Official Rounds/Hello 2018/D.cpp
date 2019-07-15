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

struct query{
	int l, t, id;
};

bool operator<(const query & a, const query & b){
	return !((a.l < b.l) || (a.l == b.l && a.t >= b.t));
}

bool cmp(const query & a, const query & b){
	return a.t < b.t || (a.t == b.t && a.l < b.l);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	priority_queue<query> pq;
	query v[n];
	for(int i=0; i<n; i++){
		cin >> v[i].l >> v[i].t;
		v[i].id = i;
	}
	sort(v, v+n, cmp);
	
	int acc = 0;
	for(int i=0; i<n; i++){
		//cout << "at exam with " << v[i].l << " limit and " << v[i].t << " time with " << acc << " acc and " << pq.size() << " exams " << endl;
		if(pq.size() >= v[i].l) continue;
		if(acc + v[i].t > k) continue;
		pq.push(v[i]);
		acc += v[i].t;
		while(!pq.empty() && pq.top().l < pq.size()){
			acc -= pq.top().t;
			pq.pop();
		}
	}
	
	cout << pq.size() << endl;
	cout << pq.size() << endl;
	bool flag = true;
	while(!pq.empty()){
		if(flag){
			flag = false;
		}
		else cout << " ";
		cout << pq.top().id+1;
		pq.pop();
	}
	cout << endl;
}
		