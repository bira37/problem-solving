#include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	cin >> a;
	char x;
	int cont = 0;
	double total = 0;
	for (int i=0; i<a.size(); i++){
		if (a[i] == '0') continue;
		cont++;
		if (a[i] == '1'){
			if (i + 1 < a.size() && a[i+1] == '0')
				total += 10;
			else total += 1;
		}
		else
			total += (a[i] - '0');
	}
	cout << fixed << setprecision(2) << total / cont << endl;
}
