#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, q;
	cin >> n >> q;
	int v[n];
	for(int i=0; i<n; i++) cin >> v[i];
	
	deque< pair<int,int> > dq;
	
	for(int i=0; i<q; i++){
		int num, ord;
		cin >> ord >> num;
	
		while(!dq.empty() && dq.back().first <= num) dq.pop_back();
		dq.push_back(make_pair(num, ord));
	}
	int right = dq.front().first;
	int ord = dq.front().second;
	sort(v, v + right);
	int l = 0, r = right-1;
	int a[n];
	for(int i=0; i<n; i++){
	    a[i] = v[i];
	}
	dq.pop_front();
	dq.push_back(make_pair(0,0));
	while(!dq.empty()){
	  int left = dq.front().first;
	  for(int i=right-1; i>=left; i--){
	    a[i] = (ord == 2 ? v[l++] : v[r--]);
	  }
	  right = left;
	  ord = dq.front().second;
	  dq.pop_front();
	}
	
	for(int i=0; i<n; i++){
		if(i) cout << " ";
		cout << a[i];
	}
	cout << endl;
}