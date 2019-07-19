#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n, k;
	set< int > s;
	map<int,int> m;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		s.insert(x);
		m[x] = i+1;
	}
	if(s.size() < k) cout << "NO" << endl;
	else {	
		cout << "YES" << endl;
		while(k > 0){
			k--;
			cout << m[(*s.begin())] << " ";
			s.erase(s.begin());
		}
		cout << endl;
	}
}
	
