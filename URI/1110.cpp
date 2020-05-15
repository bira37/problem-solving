#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n,x;
	while(cin >> n, n!=0){
		queue<int> cartas;
		queue<int> descarte;
		for(int i=1;i<=n;i++) cartas.push(i);
		cout << "Discarded cards: " << cartas.front();
		cartas.pop();
		x=cartas.front();
		cartas.pop();
		cartas.push(x);
		while(cartas.size()!= 1){
			cout << ", " << cartas.front();
			cartas.pop();
			x=cartas.front();
			cartas.pop();
			cartas.push(x);
		}
		cout<<endl<<"Remaining card: "<< cartas.front() <<endl;
	}
	return 0;
}
