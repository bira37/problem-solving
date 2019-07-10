#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	string ax = "aa";
	string bx = "bb";
	string a = "a";
	string b = "b";
	while(n>0){
		if(n > 1){
			cout << ax;
			n-=2;
		}	
		else{
			cout << a;
			n--;
		}
		swap(ax,bx);
		swap(a,b);
	} 
	cout << endl;
}
