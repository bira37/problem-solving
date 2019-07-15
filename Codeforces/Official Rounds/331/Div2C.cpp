#include <bits/stdc++.h>

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

/* Range update Segment Tree Implementation */
/* The first node (ROOT) is defined to 1 (1 - index impl) */
/* N is the maximum number of elements given by the statement */
/* Lazy can be inside node structure instead of being another structure */

#define ROOT 1
#define N 100000

struct node{
	int val;
	node(){
	  val = 0;
	}	
	node(int val) : val(val) {}
};

node tree[4*N];

node combine(node a, node b){
	node res;
	res.val = max(a.val, b.val);
	return res;
}

void range_update(int root, int l, int r, int a, long long val){
	if(l == r && l == a){
		tree[root].val = max(val,tree[root].val);
		return;
	}
	
	int m = (l+r)/2;
	
	if(a <= m) range_update(2*root, l, m, a, val);
	else range_update(2*root+1, m+1, r, a, val);

	tree[root] = combine(tree[2*root], tree[2*root+1]);
}

node query(int root, int l, int r, int a, int b){
	if(l == a && r == b) return tree[root];
	
	int m = (l+r)/2;
	if(b <= m) return query(2*root, l, m, a, b);
	else if(m < a) return query(2*root+1, m+1, r, a, b);
	else {
		node left = query(2*root, l, m, a, m);
		node right = query(2*root+1, m+1, r, m+1, b);
		node ans = combine(left, right);
		return ans;
	}
}

struct Point{
  int x,y;
  Point() {}
  Point(int x,int y) : x(x), y(y) {}
};

bool cmp(const Point & a, const Point & b){
  return a.x < b.x || (a.x == b.x && a.y <= b.y);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<Point> v(n);
	map<int, queue<int> > m;
	for(int i=0; i<n; i++){
	  cin >> v[i].x >> v[i].y;
	}
	vector<int> w(n);
	vector<Point> ans(n);
	for(int i=0; i<n; i++){
	  cin >> w[i];
	  m[w[i]].push(i);
	}
	sort(v.begin(), v.end(), cmp);
	bool ok = true;
	for(int i=0; i<n && ok; i++){
	  if(m[v[i].y - v[i].x].empty()) ok = false;
	  else if(query(ROOT, 0, N-1, 0, v[i].y).val > m[v[i].y - v[i].x].front()) ok = false;
	  else {
	     ans[m[v[i].y - v[i].x].front()] = v[i];
	     range_update(ROOT, 0, N-1, v[i].y, m[v[i].y - v[i].x].front());
	     m[v[i].y - v[i].x].pop();
	  }
	}
	
	
	if(ok){
	  cout << "YES" << endl;
	  for(int i=0; i<n; i++){
	    cout << ans[i].x << " " << ans[i].y << endl;
	  }
	}
	else cout <<  "NO" << endl;
}