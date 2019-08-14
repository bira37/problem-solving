#include <bits/stdc++.h>
#define ff first
#define ss second
#define int long long

using namespace std;

//Convex Hull - Monotone Chain
//Generates Upper and Lower Hull 

vector < pair<int, int> > upper, lower;
vector< pair<int, int> > hull;


int direction(pair<int, int> & a, pair<int, int> & b, pair<int, int> & c){
    pair<int, int> vec1(b.ff - a.ff, b.ss - a.ss);
    pair<int, int> vec2(c.ff - b.ff, c.ss - b.ss);
    return vec1.ff*vec2.ss - vec1.ss*vec2.ff;
}

void calculate_upper(vector< pair<int, int> > & p){
   	for(int i=0; i<p.size(); i++){
        	while(upper.size() >= 2 && direction(upper[upper.size()-2], upper.back(), p[i]) >= 0){
       		     upper.pop_back();
      		}
        	upper.push_back(p[i]);
    	}
}

void calculate_lower(vector< pair<int, int> > & p){
	for(int i=0; i<p.size(); i++){
        	while(lower.size() >= 2 && direction(lower[lower.size()-2], lower.back(), p[i]) <= 0){
       		     lower.pop_back();
      		}
        	lower.push_back(p[i]);
    	}
}

//void merge_hull(){
//	for(int i=0; i<upper.size(); i++) hull.insert(upper[i]);
//	for(int i=0; i<lower.size(); i++) hull.insert(lower[i]);
//}	

double dist(pair<int, int> & a, pair<int, int> & b){
	int k1 = a.ff - b.ff;
	int k2 = a.ss - b.ss;
	k1*=k1;
	k2*=k2;
	return sqrt(k1+k2);
}

int32_t main(){
	int n,d;
	while(cin >> n >> d){
		hull.clear();
		upper.clear();
		lower.clear();
		vector< pair<int ,int> > v(n);
		for(int i=0; i<n; i++) cin >> v[i].ff >> v[i].ss;
		sort(v.begin(), v.end());
		calculate_upper(v);
		calculate_lower(v);
		vector< pair<int, int> > convex;
		pair<int, int> maior(-10000000000000, -10000000000000);
		int idx = -1;
		//cout << "ROLE PELA UPPER" << endl;
		for(int i=0; i<upper.size(); i++){
			//cout << upper[i].ff << " " << upper[i].ss << endl;
			if(upper[i].ss > maior.ss){
				maior =  upper[i];
				idx = i;
			}
		}
		set< pair<int ,int> > used;
		for(int i=idx; i<upper.size(); i++){
			hull.push_back(upper[i]);
			used.insert(upper[i]);
		}
		for(int i=lower.size()-1; i>=0; i--){
			if(used.count(lower[i])) continue;
			hull.push_back(lower[i]);
			used.insert(lower[i]);
		}
		for(int i=0; i<idx; i++){
			if(used.count(upper[i])) continue;
			hull.push_back(upper[i]);
			used.insert(upper[i]);
		}
		double ans = dist(hull[0],hull[hull.size()-1]);
		for(int i=1; i<hull.size(); i++){
			ans += dist(hull[i], hull[i-1]);
		}
		cout << fixed << setprecision(2);
		cout << ans << endl;
	}
}
