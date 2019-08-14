#include <iostream>
#include <map>
using namespace std;

int main() {
	int n;
	while(cin >> n, n!=0){
		map<int,int> vis;
		int count=0;
		int acumulador = 0;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			if(vis[x] == 0){
				count+= x + acumulador++;
				vis[x]=i+1;
			}
			else{
				count+= (i-vis[x]+1);
				vis[x]=i+1;
				acumulador++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
