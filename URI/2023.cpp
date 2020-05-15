#include <bits/stdc++.h>

using namespace std;

struct kid{
	string nome;
	int id;
};

bool cmp(const kid & a, const kid & b){
	return a.nome < b.nome;
}

int main(){
	vector<kid> v;
	vector<string> registro;
	
	string x;
	int k=0;
	while(getline(cin, x)){
		registro.push_back(x);
		for(int i=0; i<x.size(); i++){
			if(x[i] >= 'A' && x[i] <= 'Z') x[i] += ('a' - 'A');
		}
		kid aux;
		aux.id = k++;
		aux.nome = x;
		v.push_back(aux);
	}
	
	sort(v.begin(), v.end(), cmp);

	cout << registro[v[v.size()-1].id] << endl;
}
