#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int soma =0;
	for(int i=0; i<n; i++){
		int x,y;
		cin >> x >> y;
		soma += x*y;
	}
	cout << soma << endl;
	return 0;
}
