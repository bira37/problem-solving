#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	int caso = 1;
	while(t--){
		cout << "Case " << caso++ << ":" << endl;
		int q;
		cin >> q;
		deque< pair<int ,int> > dq;
		map<int, int> m;
		for(int i=0; i<q; i++){
			int op;
			cin >> op;
			if(op == 1){
				char where;
				int p;
				cin >> where >> p;
				if(where == 'B'){
					dq.push_back(make_pair(i, p));
					m[p] = i;
				}
				else{
					dq.push_front(make_pair(-i, p));
					m[p] = -i;
				}
			}
			else if(op == 2){
				char where;
				cin >> where;
				if(where == 'B'){
					int x = dq.back().second;
					dq.pop_back();
					m.erase(x);
				}
				else {
					int x = dq.front().second;
					dq.pop_front();
					m.erase(x);
				}
			}
			else {
				char what;
				int p;
				cin >> what >> p;
				if(what == 'D') cout << dq[p-1].second << endl;
				else {
					int l = 0, r = dq.size()-1;
					int val = m[p];
					while(l <= r){
						int mid = (l+r)>>1;
						if(dq[mid].first == val){
							cout << mid+1 << endl;
							break;
						}
						else if(dq[mid].first > val){
							r = mid-1;
						}
						else l = mid+1;
					}
				}
			}
		}
	}
}

			
