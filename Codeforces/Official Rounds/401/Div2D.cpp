#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string v[n];
	for(int i=0; i<n; i++) cin >> v[i];
	
	for(int i=n-2; i>=0; i--){
		if(v[i][1] == v[i+1][1]){
			string aux;
			int pointer = 0;
			int pointer2 = 0;
			int size = v[i].size();
			int size2 = v[i+1].size();
			bool flag = true;
			while(pointer < size && pointer2 < size2 && v[i][pointer] <= v[i+1][pointer2]){
				if(v[i][pointer] == v[i+1][pointer2]){
					aux += v[i][pointer++];
					pointer2++;
				}
				else{
					flag = false;
					break;
				}
				//cout << pointer << " " << pointer2 << endl;
			}
			if(flag) v[i] = aux;
		}
		else if(v[i][1] > v[i+1][1]) v[i] = "#";
	}
 
	for(int i=0; i<n; i++){
		cout << v[i] << endl;
	}
}
	
