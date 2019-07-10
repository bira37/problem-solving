#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,k;
	cin >> n >> k;
	int count = 1;
	int price = n;
	while(price%10 != k && price%10 != 0){
		count++;
		price += n;
	}
	cout << count << endl;
}
