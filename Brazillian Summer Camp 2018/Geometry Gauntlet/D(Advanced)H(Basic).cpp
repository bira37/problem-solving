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
#define int long long

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

struct Point2D{
	int x,y;
	Point2D() {}
	Point2D(int x, int y) : x(x), y(y) {}
	bool operator<(const Point2D & b) const {
		return x < b.x || (x == b.x && y < b.y);
	}
};


struct Vector2D{
	int x,y;
	Vector2D() {}
	Vector2D(int x, int y) : x(x), y(y) {}
};

int cross(Vector2D & a, Vector2D & b){
	if(a.x*b.y > a.y*b.x) return 1;
	else if(a.x*b.y < a.y*b.x) return -1;
	else return 0;
}	

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	vector< Point2D > v(n),lower, upper; 
	vector< Point2D > scan;
	set< Point2D > s;
	int ans = 0;
	for(int i=0; i<n; i++){
		cin >> v[i].x >> v[i].y;
		s.insert(v[i]);
	}
	for(int i=0; i<m; i++){
		int x,y;
		cin >> x >> y;
		if(s.count(Point2D(x,y))) ans++;
		else scan.push_back(Point2D(x,y));
	}
	sort(v.begin(), v.end());
	//upper hull
	for(int i=0; i<n; i++){
		while(upper.size() >= 2){
			Vector2D v1,v2;
			v2.x = v[i].x - upper[upper.size()-2].x;
			v2.y = v[i].y - upper[upper.size()-2].y;
			v1.x = upper.back().x - upper[upper.size()-2].x;
			v1.y = upper.back().y - upper[upper.size()-2].y;
			if(cross(v1,v2) >= 0) upper.pop_back();
			else break;
		}
		upper.push_back(v[i]);
	}
	//lower hull
	for(int i=0; i<n; i++){
		while(lower.size() >= 2){
			Vector2D v1,v2;
			v2.x = v[i].x - lower[lower.size()-2].x;
			v2.y = v[i].y - lower[lower.size()-2].y;
			v1.x = lower.back().x - lower[lower.size()-2].x;
			v1.y = lower.back().y - lower[lower.size()-2].y;
			if(cross(v1,v2) <= 0) lower.pop_back();
			else break;
		}
		lower.push_back(v[i]);
	}
	for(int i=0; i<scan.size(); i++){
		Point2D p = scan[i];
		if(p.x == upper[0].x){
			if(p.y > upper[0].y){
				//upper
				if(upper[1].x != upper[0].x) continue;
				else if(p.y <= upper[1].y) ans++;
			}
			else {
				//lower
				if(lower[1].x != lower[0].x) continue;
				else if(p.y >= lower[1].y) ans++;
			}
			continue;
		}
		Vector2D v1,v2;
		//upper or lower
		int ansu = -1, ansl = -1;
		int l = 0, r = upper.size()-2;
		while(l <= r){
			int m = (l+r)>>1LL;
			if(upper[m].x < p.x && p.x <= upper[m+1].x){
				ansu = m;
				break;
			}
			else if(upper[m+1].x < p.x) l = m+1;
			else r = m-1;
		}
		l = 0, r = lower.size()-2;
		while(l <= r){
			int m = (l+r)>>1LL;
			if(lower[m].x < p.x && p.x <= lower[m+1].x){
				ansl = m;
				break;
			}
			else if(lower[m+1].x < p.x) l = m+1;
			else r = m-1;
		}
		if(ansu == -1 || ansl == -1) continue;
		bool oku = false, okl = false;
		v1.x = upper[ansu+1].x - upper[ansu].x;
		v1.y = upper[ansu+1].y - upper[ansu].y;
		v2.x = p.x - upper[ansu].x;
		v2.y = p.y - upper[ansu].y;
		oku = (cross(v1,v2) <= 0);
		v1.x = lower[ansl+1].x - lower[ansl].x;
		v1.y = lower[ansl+1].y - lower[ansl].y;
		v2.x = p.x - lower[ansl].x;
		v2.y = p.y - lower[ansl].y;
		okl = (cross(v1,v2) >= 0);
		if(oku && okl) ans++;
	}
	if(ans >= k) cout << "YES" << endl;
	else cout << "NO" << endl;
}
