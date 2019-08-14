#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	map<string, int> candidato;
	int n,maior=0;
	string r;
	cin >> n;
	for(int i=0; i < n; i++){
		cin >> r;
		candidato[r]++;
	}
	r=candidato.begin()->first;
	for(pair<string, int> x : candidato){
		if(x.second > maior){
			maior = x.second;
			r=x.first;
		}
	}
	cout << r << endl;
}
	


