#include <bits/stdc++.h>

using namespace std;

int main(){
		int n,m,t=0;
		while(cin >> n >> m, n+m){
			t++;
			cout << "Teste " << t << endl;
			int v[n];
			for(int i=0; i<n; i++){
				v[i] =0;
			}
			for(int i =0; i<m; i++){
				int x,y;
				cin >> x >> y;
				v[x-1]++;
				v[y-1]++;
			}
			int max = 0;
			for(int i=0; i<n; i++){
				max = std::max(max, v[i]);
			}
			bool flag = true;
			for(int i=0; i<n; i++){
				if(max == v[i]){
					if(flag){
						cout << i+1;
						flag = false;
					}
					else cout << " " << i+1;
				}
			}
			cout << endl << endl;
		}
}
