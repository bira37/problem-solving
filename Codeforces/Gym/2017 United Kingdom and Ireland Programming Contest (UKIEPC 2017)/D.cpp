#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	string st;
 
	cin >> st;
	int n = st.size();
	queue<int> pos[26];
	string sor = st;
	sort(sor.begin(), sor.end());
	for(int i = 0; i < n; i++) {
		pos[st[i]-'a'].push(i);
	}
	int count = 0;
 
	// cout << sor << endl;
 
	int cor[n];
	memset(cor, 0, sizeof cor);
	while(count < n) {
		for(int i = 0; i < n; i++) {
	// cout << "bla" << endl;
			if(cor[i]) continue;
 
			int c = sor[i]-'a';
			assert(count <= (10000 - 1));
			count++;
			if(i != pos[c].front()) {
				if(sor[i] > sor[pos[c].front()])
					cout << i+1 << " " << pos[c].front()+1 << endl;
				else
					cout << pos[c].front()+1 << " " << i+1 << endl;
				swap(sor[i], sor[pos[c].front()]);
			}
			cor[pos[c].front()] = 1;
			pos[c].pop();
			// cout << sor << endl;
		}
	}
	// cout << sor << endl;
}
