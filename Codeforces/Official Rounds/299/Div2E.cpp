#include <bits/stdc++.h>

#define int long long
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1

using namespace std;

inline int mod(int n){ return (n%1000000007); }

pair<int,int> operator-(const ii & a, const ii & b){
  ii ans(a.ff - b.ff, a.ss - b.ss);
  return ans;
}

map< ii , vector<int> > m;

int cut(ii o, ii b, ii a){
  	return (a.ss * b.ff * o.ff * o.ss - a.ss * o.ff * b.ff * b.ss - o.ss * b.ff * a.ff * a.ss + a.ff * b.ff * a.ss * b.ss) - 
		(a.ff * b.ss * o.ff * o.ss - a.ff * o.ss * b.ff * b.ss - o.ff * b.ss * a.ff * a.ss + a.ff * b.ff * a.ss * b.ss);
}

int32_t main(){
	DESYNC;
	int n;
	cin >> n;
	set< ii > s;
	for(int i=0; i<n; i++){
	  int x,y;
	  cin >> x >> y;
	  m[ii(x,y)].pb(i+1);
	  s.insert(ii(x,y));
	}
	vector< ii > v;
	for(ii x : s) v.pb(x);
	
	sort(v.begin(), v.end(), [](const ii & a, const ii & b){
	  return 1./a.ff < 1./b.ff || (1./a.ff == 1./b.ff && 1./a.ss < 1./b.ss);
	});
	
	ii ho = *min_element(v.begin(), v.end(), [](const ii & a, const ii & b){
	  return 1./a.ff < 1./b.ff || (1./a.ff == 1./b.ff && 1./a.ss < 1./b.ss);
	});
	
	ii ve = *min_element(v.begin(), v.end(), [](const ii & a, const ii & b){
	  return 1./a.ss < 1./b.ss || (1./a.ss == 1./b.ss && 1./a.ff < 1./b.ff);
	});
	//cout << "ho " << ho.ff << " " << ho.ss << endl;
	//cout << "ve " << ve.ff << " " << ve.ss << endl;
	vector< ii > hull;
	for(ii p : v){
	  //cout << "at " << p.ff << " " << p.ss << endl;
	  if(!hull.empty() && hull.back() == ve) break;
	  while(hull.size() >= 2 && cut(hull[hull.size()-2], hull.back(), p) > 0){
	    hull.pop_back();
	  }
	  hull.pb(p);
	}
	set<int> ans;
	for(ii p : hull){
	  for(auto k : m[p]){
	    ans.insert(k);
	  }
	}
	
	for(int x : ans) cout << x << " ";
	cout << endl;        
}