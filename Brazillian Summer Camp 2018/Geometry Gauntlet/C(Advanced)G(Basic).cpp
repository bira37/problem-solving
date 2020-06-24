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

template <class T> class Vector{
public:

	T x,y;
	
	Vector<T>() = default;
	Vector<T>(T x, T y) : x(x), y(y) {}
	
	Vector<T> operator+(const Vector<T> & b) const {
		return Vector<T>(x + b.x, y+b.y);
	}
	
	Vector<T> operator-(const Vector<T> & b) const {
		return Vector<T>(x - b.x, y - b.y);
	}
	
	T operator*(const Vector<T> & b) const {
		return x*b.x + y*b.y;
	}
	
	Vector<T> operator*(const int & b) const {
		return Vector<T>(x*b, y*b);
	}
	
	T operator^(const Vector<T> & b) const {
		return x*b.y - y*b.x;
	}
	
	bool operator<(const Vector<T> & b){
		return x < b.x || (x == b.x && y < b.y);
	}
	
	T size2(){
		return x*x + y*y;
	}

};

template <class T> class ConvexHull{
public:
	vector< Vector<T> > points;
	ConvexHull<T>() = default;
	
	void make(vector< Vector<T> > v){
		vector< Vector<T> > lower, upper;
		sort(v.begin(), v.end());
		for(int i=0; i<v.size(); i++){
			while(upper.size() >= 2 && (Vector<T>(upper.back() - upper[upper.size()-2])^Vector<T>(v[i] - upper.back())) >= 0LL) upper.pop_back();
			upper.push_back(v[i]);
		}
		reverse(v.begin(), v.end());
		for(int i=0; i<v.size(); i++){
			while(lower.size() >= 2 && (Vector<T>(lower.back() - lower[lower.size()-2])^Vector<T>(v[i] - lower.back())) >= 0LL) lower.pop_back();
			lower.push_back(v[i]);
		}
		upper.pop_back(); lower.pop_back();
		for(int i=upper.size()-1; i>=0; i--) points.push_back(upper[i]);
		for(int i=lower.size()-1; i>=0; i--) points.push_back(lower[i]);
	}
	
	T shoelace2(){
		T area2 = points.back()^points[0];
		for(int i=0; i<points.size()-1; i++){
			area2 += points[i]^points[i+1];
		}
		return area2;
	}
	
	long double perimeter(){
		long double val = sqrt(Vector<T>(points.back().x - points[0].x, points.back().y - points[0].y).size2());
		for(int i=0; i<points.size()-1; i++){
			val += sqrtl(Vector<T>(points[i+1].x - points[i].x, points[i+1].y - points[i].y).size2());
		}
		return val;
	}
		
};

bool operator<(const Vector<long long> & a, const Vector<long long> & b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

map< Vector<long long>, int> m;
	
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector < Vector<long long> > v(n);
	for(int i=0; i<n; i++){
		cin >> v[i].x >> v[i].y;
		m[v[i]] = i+1;
	}
	ConvexHull<long long> *C = new ConvexHull<long long>();
	C->make(v);
	cout << C->points.size() << endl;
	for(Vector<long long> p : C->points){
		cout << m[p] << " ";
		//cout << p.x << " " << p.y << endl;
	}
	cout << endl;
	cout << setprecision(15) << C->perimeter() << endl;
	long long area = C->shoelace2();
	if(area%2) cout << (area/2) << ".5" << endl;
	else cout << area/2 << endl;
}
