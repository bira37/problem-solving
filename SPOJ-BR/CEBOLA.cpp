#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

set< pair<int, int> > p;
vector< pair<int ,int> > v;
vector< pair<int, int> > lower, upper;

int cross(pair<int ,int> & a, pair<int, int> & b, pair<int ,int> & c){
	pair<int ,int> vec1(b.ff-a.ff, b.ss-a.ss);
	pair<int ,int> vec2(c.ff-b.ff, c.ss-b.ss);
	return vec1.ff*vec2.ss - vec1.ss*vec2.ff;
}

void calculate_upper(vector< pair<int, int> > & p){
   	for(int i=0; i<p.size(); i++){
        	while(upper.size() >= 2 && cross(upper[upper.size()-2], upper.back(), p[i]) > 0){
       		     upper.pop_back();
      		}
        	upper.push_back(p[i]);
    	}
}

void calculate_lower(vector< pair<int, int> > & p){
	for(int i=0; i<p.size(); i++){
        	while(lower.size() >= 2 && cross(lower[lower.size()-2], lower.back(), p[i]) < 0){
       		     lower.pop_back();
      		}
        	lower.push_back(p[i]);
    	}
}

int main(){
	int n;
	while(cin >> n , n != 0){
		p.clear();
		for(int i=0; i<n; i++){
			int x,y;
			cin >> x >> y;
			p.insert(make_pair(x,y));
		}
		int camada = 0;
		while(p.size() >= 3){
			upper.clear();
			lower.clear();
			v.clear();
			for(pair<int, int> x : p) v.push_back(x);
			calculate_upper(v);
			calculate_lower(v);
			for(int i=0; i<upper.size(); i++){
				p.erase(upper[i]);
			}
			for(int i=0; i<lower.size(); i++){
				p.erase(lower[i]);
			}
			camada++;
		}
		if(p.size() > 0) cout << "Do not take this onion to the lab!" << endl;
		else if(camada%2) cout << "Take this onion to the lab!" << endl;
		else cout << "Do not take this onion to the lab!" << endl;
	}
}
