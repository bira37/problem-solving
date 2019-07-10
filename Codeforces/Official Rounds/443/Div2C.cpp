#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	int l = 0 , r = 1023;
	for(int i=0; i<n; i++){
		char c;
		int x;
		cin >> c >> x;
		if(c == '|') l |= x, r |= x;
		else if(c == '&') l &= x, r &= x;
		else l ^= x, r ^= x;
	}
	int ou=0;
	int xou=0;
	for(int i=0; i<10; i++){
		bool x = l & (1 << i);
		bool y = r & (1 << i);
		//cout << x << " " << y << endl;
		if(x & y){
			ou |= (1 << i);
		}
		else if(x & !y){
			xou |= (1 << i);
		}
		else if(!x & !y){
			//cout << "epa " << (1 << i) << endl;
			//cout << "eeeei " << (ou | (1 << i)) << " " << (xou | (1 << i)) << endl;
			ou = ou | (1 << i);
			xou = xou | (1 << i);
			//cout << "preview " << ou << " " << xou << endl;
		}
	}
	cout << 2 << endl;
	cout << "| " << ou << endl;
	cout << "^ " << xou << endl; 
}
