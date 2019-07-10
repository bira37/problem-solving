#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	int place = (k+1)/2;
	int posx = 0, posy = 0;
	int count = 0;
	for(int i=1; i<=n; i++){
		posx++;
		posy = 0;
		for(int j=1; j<=m; j++){
			count++;
			posy++;
			if(count == place){
				cout << posx << " " << posy << " ";
				if(k%2==1) cout << "L" << endl;
				else cout << "R" << endl;
				return 0;
			}
		}
	}
}
