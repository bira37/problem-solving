#include <bits/stdc++.h>

using namespace std;

int main(){
	int max = 0, pos = 0;
	for(int i=0; i<100; i++){
		int x;
		cin >> x;
		if(x > max){
			pos = i+1;
			max = x;
		}
	}
	cout << max << endl << pos << endl;
}
