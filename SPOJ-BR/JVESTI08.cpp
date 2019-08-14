#include <iostream>
using namespace std;

int main() {
	string x;
	int n, cont = 0;
	cin >> n;
	cin >> x;
	for(int i=0; i<n; i++){
		char y;
		cin >> y;
		if(y==x[i]) cont ++;
	}
	cout << cont << endl;

	return 0;
}
