#include <bits/stdc++.h>
 
using namespace std;
 
struct info{
	int s, sum, id;
	info() {}
	info(int s, int sum, int id) : s(s), sum(sum), id(id) {}
	bool operator<(const info & b) const {
		return sum < b.sum || (sum == b.sum && s < b.s) || (sum == b.sum && s == b.s && id < b.id);
	}
};
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	set< info > av;
	
	vector<int> seq[n];
	
	for(int i=0; i<n; i++){
		int l;
		cin >> l;
		seq[i].resize(l);
		int sum = 0;
		for(int j = 0; j<l; j++){
			cin >> seq[i][j];
			sum += seq[i][j];
		}
		
		for(int j=0; j<l; j++){
			av.insert({i, sum - seq[i][j], j+1});
		}
	}
	
	for(int i=0; i<n; i++){
		int sum = 0;
		int l = seq[i].size();
		for(int j = 0; j<l; j++){
			sum += seq[i][j];
		}
		for(int j=0; j<l; j++){
			av.erase(av.find(info(i, sum - seq[i][j], j+1)));
		}
		for(int j=0; j<l; j++){
			auto it = av.lower_bound(info(-1, sum - seq[i][j], -1));
			if(it == av.end()) continue;
			info cur = *it;
			if(cur.sum != sum - seq[i][j]) continue;
			cout << "YES" << endl;
			cout << i+1 << " " << j+1 << endl;
			cout << cur.s+1 << " " << cur.id << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}
