#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, pair<int, pair<int, int> > > & a, const pair<int, pair<int, pair<int, int> > > & b){
	if(a > b )
		return true;
	else return false;
}

int main(){
	int n,m,o,p,b;
	cin >> n >> m;
	vector< pair<int, pair<int, pair<int, int> > > > med(n);
	for(int i=0; i<n; i++) med[i].second.second.second=-1*(i+1);
	for(int i=0; i<m; i++){
		cin >> o >> p >> b;
		med[o-1].first++;
		med[p-1].second.first++;
		med[b-1].second.second.first++;
	}
	sort(med.begin(),med.end(),cmp);
	for(int i=0; i<n; i++){
		cout << -1*med[i].second.second.second;
		if(i<n-1) cout << " ";
	}
	cout << endl;
}

