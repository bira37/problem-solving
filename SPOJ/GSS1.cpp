#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define int long long
#define ieps (int) 1e6
#define eps (int) 1e9
#define pii pair<int,int>

int n , m;

int v[ieps];

struct node{
	int prf , sfx , ans , sum;
	void setval(int v){
		prf = sfx = ans = sum = v;
	}
};

node st[ieps*4];

node putnewval(node a , node b){
	node x;
	x.prf = -1000000000000;
	x.sfx = x.prf;
	x.ans = x.sfx;
	x.sum = x.ans;
	x.prf = max(a.prf , a.sum + b.prf);
	x.sfx = max(b.sfx , b.sum + a.sfx);
	x.sum = a.sum + b.sum;
	x.ans = max(a.ans , max(b.ans , a.sfx + b.prf));
	return x;
}

void build(int l  , int r  , int currnode ){
	if(l == r){
		st[currnode].setval(v[l]);
		return;
	}
	int mid = (l+r)/2;
	build(l , mid , 2*currnode);
	build(mid + 1 , r , 2*currnode + 1);
	st[currnode] = putnewval(st[2*currnode] , st[2*currnode + 1]);
}

node query(int x , int y , int l  , int r , int currnode){
	if(x == l && y == r){
		return st[currnode];
	}
	int mid = (l+r)/2;
	if(y <= mid){
		return query(x , y , l , mid , 2*currnode);
	}
	if(x > mid){
		return query(x , y, mid + 1 , r , 2*currnode + 1);
	}
	return putnewval(query(x,mid , l, mid , 2*currnode) , query(mid + 1 , y, mid + 1 , r , 2*currnode + 1));
}


int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0) , cout.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++) cin>>v[i];
	cin>>m;
	build(0 , n- 1 , 1);
	for(int i = 0;i<m;i++){
		int x , y;
		cin>>x>>y;
		x-- , y--;
		node p =query(x , y , 0 , n-1 , 1);
		cout<<p.ans<<endl;
	}
}

