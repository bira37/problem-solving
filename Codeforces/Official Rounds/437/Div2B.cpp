#include <bits/stdc++.h>
 
#define ROOT 1
 
using namespace std;
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	if(n == 1){
		cout << "1 1" << endl << "1" << endl;
		return 0;
	}
	int k = 2*(n-1);
	cout << k << " " << 2 << endl;
	cout << "1 2" << endl;
}
