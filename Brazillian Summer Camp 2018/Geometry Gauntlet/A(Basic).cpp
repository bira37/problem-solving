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
	
	T operator*(const Vector<T> & b) const {
		return x*b.x + y*b.y;
	}
	
	Vector<T> operator*(const int & b) const {
		return Vector<T>(x*b, y*b);
	}
	
	T operator^(const Vector<T> & b) const {
		return x*b.y - y*b.x;
	}
	
	T size2(){
		return x*x + y*y;
	}

};
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Vector<double> v[2];
	for(int i=0; i<2; i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		v[i] = Vector<double>(c-a, d-b);
	}
	cout << fixed << setprecision(20) << sqrt(v[0].size2()) << " " << sqrt(v[1].size2()) << endl;
	Vector<double> sum = v[0]+v[1];
	cout << sum.x << " " << sum.y << endl;
	cout << v[0]*v[1] << " " << (v[0]^v[1]) << endl;
	cout << fabs(v[0]^v[1])/2.0 << endl;
}
