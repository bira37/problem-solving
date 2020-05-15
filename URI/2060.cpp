#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	int c2=0,c3=0,c4=0,c5=0;
	for(int i=0; i<t; i++){
		int x;
		cin >> x;
		if(x%2 == 0) c2++;
		if(x%3 == 0) c3++;
		if(x%4 == 0) c4++;
		if(x%5 == 0) c5++;
	}
	cout << c2 << " Multiplo(s) de 2" << endl;
	cout << c3 << " Multiplo(s) de 3" << endl;
	cout << c4 << " Multiplo(s) de 4" << endl;
	cout << c5 << " Multiplo(s) de 5" << endl;
}
		
